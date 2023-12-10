# Pipsqueak

An insignificant engine for insignificant applications.

Pipsqueak is a framework for creating interactive applications, such as games.

I am developing this for fun and learning, so its purpose is not to provide a
fully featured engine or compete with other (game) engines.

## Setup

All commands listed here, except those in the "Prerequisites" section, should be
run from the repository's root directory unless otherwise specified.

### Prerequisites

- [Git][git]
- [CMake 3.23.0 or later][cmake]
- Some C++ build environment, such as g++ (≥ 13) and Make or MSVC.

On Linux, you also need the X11 development libraries to build GLFW, which is a
dependency of Pipsqueak:

```bash
sudo apt update
sudo apt install xorg-dev
```

If this command does not work on your distribution, check
[GLFW's documentation][glfw-deps].

Clone the repository and initialize its submodules:

    git submodule update --init --recursive

### Building

Generate the project files needed for your build environment:

    cmake -B "./build"

You can now manually use your build environment of choice to build the project,
or have CMake handle it by running:

    cmake --build "./build"


[git]:       <https://git-scm.com/>
[cmake]:     <https://cmake.org/>
[glfw-deps]: <https://www.glfw.org/docs/3.3/compile.html#compile_deps>
