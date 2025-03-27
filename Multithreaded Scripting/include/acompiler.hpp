
#pragma once

#include <filesystem>

namespace almond::compiler {
    bool compile_script_to_dll(const std::filesystem::path& input, const std::filesystem::path& output);
}
