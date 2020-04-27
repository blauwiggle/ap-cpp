# Exercises for lecture Advanced Programming in C++

This is the home of exercises for the lecture Advanced Programming in C++ taught at HdM.

## Prerequisites

There are a few prerequisites that have to be met to build the exercises. Before you install them, first check which one is probably already installed on your system. I generally recommend you also use Visual Studio Code with GCC. So if you have issues there are more people which may have experienced similar issues and can help you.

### CMake

[CMake](https://cmake.org/) is a meta build system, which allows to automatically generates configurations for other build systems (e.g. [GNU Make](https://www.gnu.org/software/make/), [Ninja](https://ninja-build.org/) or [MSBuild](https://github.com/microsoft/msbuild). CMake is platform independent and supported by various editors and IDEs, e.g. ([Visual Studio Code](https://code.visualstudio.com/), [Qt Creator](https://www.qt.io/product), [CLion](https://www.jetbrains.com/clion/), [Visual Studio](https://visualstudio.microsoft.com/vs/), ... )

### Build System

With CMake, you can choose from many build systems:

- [GNU Make](https://www.gnu.org/software/make/) is usually available on most Linux distributions, on OS X, and may be installed on Windows, too.

- [Ninja](https://ninja-build.org/) is a minimalisitc build system which is optimized for speed. It is low-level and usually target of build system generators like CMake

- [MSBuild](https://github.com/microsoft/msbuild) is the Microsoft build engine and is shipped with Visual Studio. It is widely used on the Microsoft Windows platform.

### Compiler

C++ programs have to be compiled to machine code before they can run. There are various compilers available which you can use:

- [GCC](https://gcc.gnu.org/) The GNU Compiler Collection includes a compiler for C++ and is installed on most Linux systems. It can also be used on Windows through the [MinGW](http://www.mingw.org/) project.

- [Clang](https://clang.llvm.org/) is a modern C++ compiler based on LLVM and is available on all desktop platforms.

- [MSVC](https://de.wikipedia.org/wiki/Visual_C%2B%2B) is available for Microsoft Windows and is bundled with [Visual Studio](https://visualstudio.microsoft.com/vs/). You can also install it stand-alone with the [Build Tools for Visual Studio](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019).

### Editor/IDE

There are plenty of editors and IDEs available for various platforms. The Visual Studio Code editor is used in the lecture. You can expect least friction when you also choose it. You may, however, prefer alternatives some of which are listed below.

- [Visual Studio Code](https://code.visualstudio.com/) It is freely available on all major platforms and it supports C++ and CMake through extensions. You need to setup some extensions which can be installed from within the editor to get C++ and CMake support:

  - [C/C++](https://github.com/microsoft/vscode-cpptools): Provides general support for C++ with syntax highlighting, code completion, and debugging
  - [CMake](https://github.com/twxs/vs.language.cmake): Provides syntax highlighting and code completion for CMake files
  - [CMake Tools](https://github.com/microsoft/vscode-cmake-tools): Integrates the CMake build system into VSCode. Needed to directly run CMake projects

- [Qt Creator](https://www.qt.io/product) is the offical cross-platform IDE from the creators of the Qt C++ GUI framework. It has native CMake support and is available for free.

- [CLion](https://www.jetbrains.com/clion/) A C++ IDE from JetBrains which natively supports CMake. You generally have to buy a license. You may also get it [for free](https://www.jetbrains.com/de-de/community/education/#students) as a student.

- [Visual Studio](https://visualstudio.microsoft.com/vs/) Not to be confused with Visual Studio _Code_. It is the official IDE from Microsoft for Windows targets. You need to [install CMake support](https://docs.microsoft.com/de-de/cpp/build/cmake-projects-in-visual-studio?view=vs-2019) to have CMake integration directly in the IDE. Visual Studio is available for free for private use and companies with up to five developers.

- [Xcode](https://developer.apple.com/xcode/) The official IDE for Apple devices. CMake can generate Xcode projects.

## Exercises

Here is an overview of the exercises. The list will be extended during the semester.

1. [Implement a ToDo list.](doc/todo_list.md)
