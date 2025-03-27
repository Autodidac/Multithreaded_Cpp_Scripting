
#include "ascriptingsystem.hpp"
#include "ataskscheduler.hpp"

#include <chrono>
#include <filesystem>
#include <iostream>
#include <thread>

int main() {
    TaskScheduler scheduler;

    std::cout << "[Engine] Starting up...\n";

    std::string scriptName = "editor_launcher";

    if (!almond::load_or_reload_script(scriptName, scheduler)) {
        std::cerr << "[Engine] Initial script load failed.\n";
    }

    auto lastCheck = std::filesystem::last_write_time("src/scripts/" + scriptName + ".ascript.cpp");
    auto start = std::chrono::steady_clock::now();

    while (true) {
        auto now = std::filesystem::last_write_time("src/scripts/" + scriptName + ".ascript.cpp");
        if (now != lastCheck) {
            std::cout << "\n[Engine] Detected change in script source, recompiling...\n";
            almond::load_or_reload_script(scriptName, scheduler);
            lastCheck = now;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        if (std::chrono::duration_cast<std::chrono::minutes>(std::chrono::steady_clock::now() - start).count() > 10) break;
    }

    std::cout << "[Engine] Session ended.\n";
    return 0;
}
