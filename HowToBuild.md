# How To Build

If you're having issues, send me an [email](development@kortlepel.com) or open an issue on GitHub if you believe that it is an issue with the repo itself.

## Linux

### Using `make.sh`

This is the easiest way to build. This is what I use exclusively during development. 

The script ensures that the libraries exist by building them and sym-linking the relevant files and folders to the local `lib/` and `include/` directories.

1. Run `./make.sh`
2. Done!

You can now start the game with `./bin/dungeon-engine` (it's important that you call it like that, otherwise it won't find the resources!

### Without `make.sh`

Open `make.sh` in a text editor and run the commands (or their equivalents) in sequence. It's important that the symlinks or copies of those files and folders exist in the local `lib` and `include` directories and can be statically linked against. It's also important that the exact versions of libraries are used that are included as submodules.

If everything goes well, you can then start the game with `./bin/dungeon-engine` (it's important that you call it like that, otherwise it won't find the resources!

## Other Platforms (Windows, MacOS, etc.)

Other platforms are currently not supported, but I'm working towards that and the code and libraries are very portable (for the most part). 

**What you'd need to do to get it to work:**

* Build the libraries SFML, GLFW, String, gli, glew with preferably static linkage and copy / link the include directories to the local `include` directory used by the project.

    The same goes for the `lib` directory. 

    Directory structure expected by the build system: 

    (NOTE: the `include/GL` directory is expected to have all the `glew` include files)
    ``` 
    include
    ├── GL
    │   ├── glew.h
    │   └── ...
    ├── GLFW
    │   ├── glfw3.h
    │   └── ...
    ├── SFML
    │   ├── Graphics.hpp
    │   └── ...
    ├── String
    │   ├── Core.h
    │   ├── String.h
    │   └── ...
    └── gli
        ├── gli.hpp
        └── ...
    lib
    ├── libGLEW...
    ├── libString...
    ├── libglfw3...
    ├── libsfml-graphics-s...
    └── ...
    ```

* Change the `CMakeLists.txt` to use a compiler & linker supported on your platform

* Ensure that the `bin` directory exists, then just run CMake and Make from `bin`. This will likely result in a bunch of errors.

* Fix the code errors. Most of the code is very portable, but some unix/\*nix specific things are used here and there. These *should* be easy to fix. Trying to build and run the `all_tests` target is probably a good starting point.

*If you're interested in building this on a platform that is currently not supported, I'm definitely interested in merging any changes needed to make that work!*

The ultimate goal is to distribute on Linux and Windows.
