cmake_minimum_required(VERSION 2.6)

# Cmake options
enable_testing()

set(PROJECT_NAME TypeRight)
project(${PROJECT_NAME})

##################################
# Normal Libraries & Executables #
##################################

# Find SDL
## Engineering Machine
if (EXISTS "/afs/nd.edu/user14/csesoft/new/lib")
    set(SDL2_LIBRARIES -L"/afs/nd.edu/user14/csesoft/new/lib" -lSDL2 -Wl,-rpath=/afs/nd.edu/user14/csesoft/new/lib)
    set(SDL2_INCLUDE_DIRS "/afs/nd.edu/user14/csesoft/new/include")
# Cygwin
elseif(CYGWIN)
    set(SDL2_LIBRARIES -L"/usr/local/lib" -lSDL2 -Wl,-rpath=/usr/local/lib)
    set(SDL2_INCLUDE_DIRS "/usr/local/include")
else()
    include(FindPkgConfig)
    pkg_search_module(SDL2 REQUIRED sdl2)
endif()
include_directories(${SDL2_INCLUDE_DIRS})

# Add SDLWrapper library
add_library(sdlwrapper_lib SDLWrapper.cpp)
target_link_libraries(sdlwrapper_lib ${SDL2_LIBRARIES})

# TypeRight Library
add_library(TypeRight_lib TypeRight.cpp)
target_link_libraries(TypeRight_lib sdlwrapper_lib ${SDL2_LIBRARIES})

# main
add_executable(main main.cpp)
target_link_libraries(main ${SDL2_LIBRARIES} sdlwrapper_lib TypeRight_lib)

###########
# Testing #
###########
add_subdirectory(gtest)


# Include gtest library
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(main_unittests main_unittests.cpp)
target_link_libraries(main_unittests sdlwrapper_lib gtest gtest_main)

add_test(main_unittests main_unittests)
