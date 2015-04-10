# TypeRight
TypeRight CSE 20212 Final Project

## How to setup
In order to build the files, you will need to install SDL2, sdl2_image, sdl2_ttf and CMake on
your local machine. The engineering machines alreaedy have them both.

### Mac OS X
Install [homebrew](http://coolestguidesontheplanet.com/installing-homebrew-os-x-yosemite-10-10-package-manager-unix-apps/).
Install required libraries

```
brew install pkgconfig
brew install sdl2
brew install sdl2_image
brew install sdl2_ttf
brew install cmake
```
To build the files, change into the build directory and run:
`$ cmake ..`

On the engineering machines, you will have to do 
`$ cmake -G "Unix Makefiles" ..`
from the build directory

This will analyze your system and create a makefile in that directory. To make
the executables run:
`$ make`

This will create the executables in that build directory. Git has been set up
to ignore the build directory completely, so don't worry about adding binaries. 
`make clean` will clean up the binaries. This shouldn't be necessary unless you
are changing header files. 



### Cygwin
To install the required libraries, you must compile them from source. Download
[sdl2](https://www.libsdl.org/release/SDL2-2.0.3.tar.gz) and
[sdl2_image](https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.0.tar.gz).
[sdl2_ttf](http://www.libsdl.org/projects/SDL_ttf/)
Extract them, cd into their respective directories, and run 
```
./configure
make
make install
```

This will install the two libraries into cygwin.
In order to use Cygwin on Windows, make sure that you have the cmake package
installed (as well as gcc, g++, make, etc). You can install it by rerunning the
Cygwin installer and checking the cmake package (your other packages will not
be removed, Cygwin lets you run the installer multiple times to install new
packages). 
Once you have cmake and the other tools installed, cd into the build directory
and run `$ cmake ..`. This will generate a windows specific Makefile. Run `$
make` to make the executable. A `main.exe` and `main_unittests.exe` should be
created. `main.exe` can be opened like any other executable (using `./main.exe`
notation).



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
### Week of March 9th
- [x] Get Repo on local machine using git (Everybody)
- [x] Install Cmake (everybody)
- [x] Install sdl2  on local machines (everybody)
- [x] Figure out how to compile on windows machine (Charles)
- [x] Figure out how to compile on engineering machines (Charles)

- [x] Setup Automated testing (TravisCI)
- [x] Make basic makefile for sdl
- [x] Write loadSprite method that loads sprites and write 
    example Bruh Sprite class (Charles)
- [x] Add dt to sprite class
- [x] Create Sprite Factory

### Week of March 16th
- [x] Create Level class (charles)
- [x] Scrolling background (madelyn)
- [x] Refactor scrolling background into Background class (subclass of sprite) (madelyn)
- [x] 4 Sprites (Jared)


### Week of March 23rd

### Week of March 30th
- [ ] Get working motion (Jared)
- [ ] Fix background breaks (Jared)
- [ ] collision detection (Elliott)
- [ ] Hero death (Elliott)
- [x] Text library (Charles) 
- [ ] Make background size not hard coded (Charles)
- [ ] Clean up images folder (Madelyn)
- [ ] 3 levels with backgrounds (Madelyn)
- [ ] Send sprite list to Jared that correspond with backgrounds (Madelyn)
