# Multithreaded_Cpp_Scripting

## Overview

Multithreaded_Cpp_Scripting is a state-of-the-art C++20 cross-platform "fiber-like" coroutine-based task scheduler with C++20 scripting, hot-reloading, and multithreading capabilities. This project leverages the latest features of C++20 to provide a robust and efficient scripting solution suitable for a wide range of applications.

## Features

- **Coroutine-based Task Scheduler**: Efficient task scheduling using C++20 coroutines.
- **C++20 Scripting**: Write scripts in modern C++ with full access to language features.
- **Hot-Reloading**: Reload scripts without restarting the application.
- **Multithreading**: Take full advantage of multicore processors for concurrent task execution.

## Getting Started

### Prerequisites

- A C++20 compatible compiler (e.g., GCC 10+, Clang 10+, MSVC 2019+)
- CMake 3.15 or higher
- Git

### Installation

1. **Clone the Repository**:
    ```sh
    git clone https://github.com/Autodidac/Multithreaded_Cpp_Scripting.git
    cd Multithreaded_Cpp_Scripting
    ```

2. **Build the Project**:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Run the Application**:
    ```sh
    ./Multithreaded_Cpp_Scripting
    ```

## Usage

### Writing Scripts

Scripts can be written in C++20 and can leverage all language features. Here is a simple example script:

```cpp
#include <iostream>

void script_main() {
    std::cout << "Hello from script!" << std::endl;
}
```

### Hot-Reloading

To enable hot-reloading, ensure your script files are monitored for changes. The application will automatically reload the modified scripts without requiring a restart.

## Contributing

We welcome contributions! Please follow these steps to contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes.
4. Commit your changes (`git commit -m 'Add some feature'`).
5. Push to the branch (`git push origin feature-branch`).
6. Create a new Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [C++20 Coroutines](https://en.cppreference.com/w/cpp/language/coroutines)
- [CMake](https://cmake.org/)
