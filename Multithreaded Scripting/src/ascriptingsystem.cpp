#include "ascriptingsystem.hpp"
#include "acompiler.hpp"
#include "aenginebindings.hpp"
#include "ataskscheduler.hpp"
#include <iostream>
#include <filesystem>

#ifdef _WIN32
#include <Windows.h>
static HMODULE lastHandle = nullptr;
#else
#include <dlfcn.h>
static void* lastHandle = nullptr;
#endif

namespace almond {

    using run_script_fn = void(*)(TaskScheduler&);

    bool load_or_reload_script(const std::string& name, TaskScheduler& scheduler) {
        std::filesystem::path cppPath = "src/scripts/" + name + ".ascript.cpp";
        std::filesystem::path dllPath = "src/scripts/" + name + ".dll";

        // 🔁 Unload previously loaded DLL
        if (lastHandle) {
#ifdef _WIN32
            FreeLibrary(lastHandle);
#else
            dlclose(lastHandle);
#endif
            lastHandle = nullptr;
        }

        if (!compiler::compile_script_to_dll(cppPath, dllPath)) {
            std::cerr << "[script] failed to compile script: " << name << "\n";
            return false;
        }

#ifdef _WIN32
        HMODULE handle = LoadLibraryA(dllPath.string().c_str());
        if (!handle) {
            std::cerr << "[script] failed to load DLL: " << dllPath << "\n";
            return false;
        }

        auto entry = reinterpret_cast<run_script_fn>(GetProcAddress(handle, "run_script"));
        lastHandle = handle;
#else
        void* handle = dlopen(dllPath.string().c_str(), RTLD_NOW);
        if (!handle) {
            std::cerr << "[script] failed to load DLL: " << dllPath << "\n";
            return false;
        }

        auto entry = reinterpret_cast<run_script_fn>(dlsym(handle, "run_script"));
        lastHandle = handle;
#endif

        if (!entry) {
            std::cerr << "[script] no entry point found in DLL: " << name << "\n";
            return false;
        }

        entry(scheduler);
        return true;
    }

} // namespace almond
