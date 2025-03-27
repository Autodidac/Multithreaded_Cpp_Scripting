#pragma once

#include <iostream>

// Internally defined macro for "exporting" script functions (in a script) in order to "import" them in the engine/editor
// all a bit confusing but this just keeps scripts from containing this line of code and having to write it every time
#define scriptimport __declspec(dllexport)

extern "C" void engine_print(const char* msg) {
    std::cout << "[Engine] " << (msg ? msg : "(null)") << std::endl;
}
