# TypeRight
TypeRight CSE 20212 Final Project

## How to setup
To build the files, change into the build directory and run:
`$ cmake ..`

This will analyze your system and create a makefile in that directory. To make
the executables run:
`$ make`

This will create the executables in that build directory. Git has been set up
to ignore the build directory completely, so don't worry about adding binaries. 
`make clean` will clean up the binaries. This shouldn't be necessary unless you
are changing header files. 

## Adding new executables
To add a new executable, open the CMakeLists.txt file in the root directory.
Find the section labeled "Normal Libraries & Executables" and follow the
example given. `add_executable(test test.cpp)` will add an executable named
`test` compiled from the `test.cpp` file. If you need to include other
libraries in the compilation, use the `target_link_libraries(exec_name
lib_name)` function. Examples are in tehe CMakeLists.txt file. Note you will
have to rerun `cmake ..` from your build dir to rebuild the Makefile.

## Testing
To run the testing suite, cd into the build directory (after generating the
makefile) and run `$ make test`. This will run all the tests that have been
added. If you want better testing output, run the build/main_unittests
executable.


## Todos
- [x] Setup Automated testing (TravisCI)
- [x] Make basic makefile for sdl
