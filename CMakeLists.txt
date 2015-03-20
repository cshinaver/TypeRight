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
    set(SDL2_IMAGE_LIBRARIES -L"/usr/local/lib" -lSDL2_image)
    set(SDL2_IMAGE_INCLUDE_DIRS "/usr/local/include")
else()
    include(FindPkgConfig)
    pkg_search_module(SDL2 REQUIRED sdl2)
    set(SDL2_IMAGE_LIBRARIES -L"/usr/local/lib" -lSDL2_image)
    set(SDL2_IMAGE_INCLUDE_DIRS "/usr/local/include")
endif()
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# TRTexture Class
add_library(TRTexture_lib TRTexture.cpp)
target_link_libraries(TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Sprite Class
add_library(Sprite_lib Sprite.cpp)
target_link_libraries(Sprite_lib sdlwrapper_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# SDLWrapper Class
add_library(sdlwrapper_lib SDLWrapper.cpp)
target_link_libraries(sdlwrapper_lib TRTexture_lib Sprite_lib SpriteFactory_lib)

# TypeRight Class
add_library(TypeRight_lib TypeRight.cpp)
target_link_libraries(TypeRight_lib sdlwrapper_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} Background_lib)

# Bruh Class
add_library(Bruh_lib Bruh.cpp)
target_link_libraries(Bruh_lib Sprite_lib sdlwrapper_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Background Class
add_library(Background_lib Background.cpp)
target_link_libraries(Background_lib Sprite_lib sdlwrapper_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# SpriteFactory Class
add_library(SpriteFactory_lib SpriteFactory.cpp)
target_link_libraries(SpriteFactory_lib sdlwrapper_lib)

# main
add_executable(main main.cpp)
target_link_libraries(main ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} sdlwrapper_lib TypeRight_lib Bruh_lib)

###########
# Testing #
###########
add_subdirectory(gtest)


# Include gtest library
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(main_unittests main_unittests.cpp)
target_link_libraries(main_unittests sdlwrapper_lib gtest gtest_main SpriteFactory_lib Bruh_lib)

add_test(main_unittests main_unittests)

set(CMAKE_BUILD_TYPE Debug)
