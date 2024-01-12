# cpp-principles-and-patterns

## About
This repository is a collection of practical examples of [C++ソフトウェア設計―高品質設計の原則とデザインパターン](https://www.oreilly.co.jp/books/9784814400454/) (原題: *C++ Software Design: Design Principles and Patterns for High-Quality Software*).

## Directoris
The directory structure is based on [The Pitchfork Layout (PFL)](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs).
(But there are some differences.)
(The unnecessary directories may be temporarily deleted.)

- `include/` : Contains public header files for users.
- `src/` : Contains source files (including private header files and cmake scripts).
- `test/` : Contains test files.
- `examples/` : Contains example files.
- `external/` : Contains source files and libraries from external projects.
- `data/` : Contains not explicitly code files.
- `tool/` : Contains scripts and tools.
  - `cmake/` : Contains CMake scripts.
- `doc/` : Contains documents.

The following directories are not included in the repository, but these names are reserved.
- `build/` : Temporary build directory.
- `install/` : Temporary install directory.

## Template
This repository is created from the template, [ryomashita/cpp-cmake-template](https://github.com/ryomashita/cpp-cmake-template).

The tepmplate includes configurations for the following tools:
+ [CMake](https://cmake.org/)
+ [VSCode](https://code.visualstudio.com/)
+ [Google Test](https://github.com/google/googletest)
+ [clang-format](https://clang.llvm.org/docs/ClangFormat.html)
+ [clang-tidy](https://clang.llvm.org/extra/clang-tidy/)
