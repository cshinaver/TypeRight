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
    set(SDL2_TTF_LIBRARIES -L"/usr/local/lib" -lSDL2_ttf)
    set(SDL2_TTF_INCLUDE_DIRS "/usr/local/lib")
else()
    include(FindPkgConfig)
    pkg_search_module(SDL2 REQUIRED sdl2)
    set(SDL2_IMAGE_LIBRARIES -L"/usr/local/lib" -lSDL2_image)
    set(SDL2_IMAGE_INCLUDE_DIRS "/usr/local/include")
    set(SDL2_TTF_LIBRARIES -L"/usr/local/lib" -lSDL2_ttf)
    set(SDL2_TTF_INCLUDE_DIRS "/usr/local/include")
endif()
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${SDL2_TTF_INCLUDE_DIRS})

# TRTexture Class
add_library(TRTexture_lib TRTexture.cpp)
target_link_libraries(TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Sprite Class
add_library(Sprite_lib Sprite.cpp)
target_link_libraries(Sprite_lib sdlwrapper_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# SDLWrapper Class
add_library(sdlwrapper_lib SDLWrapper.cpp)
target_link_libraries(sdlwrapper_lib TRTexture_lib Sprite_lib SpriteFactory_lib ${SDL2_TTF_LIBRARIES})

# Menu Class
add_library(Menu_lib Menu.cpp)
target_link_libraries(Menu_lib sdlwrapper_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Bruh Class
add_library(Bruh_lib Bruh.cpp)
target_link_libraries(Bruh_lib Sprite_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Lightsaber Class
add_library(Lightsaber_lib Lightsaber.cpp)
target_link_libraries(Lightsaber_lib Sprite_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Hero Class
add_library(Hero_lib Hero.cpp)
target_link_libraries(Hero_lib Sprite_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Fireball Class
add_library(Fireball_lib Fireball.cpp)
target_link_libraries(Fireball_lib Sprite_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Dragon Class
add_library(Dragon_lib Dragon.cpp)
target_link_libraries(Dragon_lib Sprite_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Pegasus Class
add_library(Pegasus_lib Pegasus.cpp)
target_link_libraries(Pegasus_lib Sprite_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Soldier Class
add_library(Soldier_lib Soldier.cpp)
target_link_libraries(Soldier_lib Sprite_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Skeleton Class
add_library(Skeleton_lib Skeleton.cpp)
target_link_libraries(Skeleton_lib Sprite_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Cat Class
add_library(Cat_lib Cat.cpp)
target_link_libraries(Cat_lib Sprite_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Snail Class
add_library(Snail_lib Snail.cpp)
target_link_libraries(Snail_lib Sprite_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Background Class
add_library(Background_lib Background.cpp)
target_link_libraries(Background_lib Sprite_lib sdlwrapper_lib TRTexture_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# TypeRight Class
add_library(TypeRight_lib TypeRight.cpp)
target_link_libraries(TypeRight_lib sdlwrapper_lib Level1_lib Level2_lib Level3_lib GameOver_lib Background_lib Bruh_lib Fireball_lib Dragon_lib Menu_lib Lightsaber_lib Hero_lib Pegasus_lib Cat_lib Soldier_lib Skeleton_lib Snail_lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# SpriteFactory Class
add_library(SpriteFactory_lib SpriteFactory.cpp)
target_link_libraries(SpriteFactory_lib sdlwrapper_lib Bruh_lib Fireball_lib Dragon_lib Lightsaber_lib Hero_lib Cat_lib Soldier_lib Skeleton_lib Snail_lib SlowDownPowerup_lib Pegasus_lib)

# Level Class
add_library(Level_lib Level.cpp)
target_link_libraries(Level_lib Background_lib sdlwrapper_lib Sprite_lib Collision_lib)

# Level 1 Class
add_library(Level1_lib Level1.cpp)
target_link_libraries(Level1_lib Level_lib)

# Level 2 Class
add_library(Level2_lib Level2.cpp)
target_link_libraries(Level2_lib Level_lib)

# Level 3 Class
add_library(Level3_lib Level3.cpp)
target_link_libraries(Level3_lib Level_lib)

# GameOver Class
add_library(GameOver_lib GameOver.cpp)
target_link_libraries(GameOver_lib sdlwrapper_lib)

# Collision Class
add_library(Collision_lib collision.cpp)
target_link_libraries(Collision_lib Sprite_lib)

# SlowDownPowerup Class
add_library(SlowDownPowerup_lib slowDownPowerup.cpp)
target_link_libraries(SlowDownPowerup_lib Sprite_lib)

# main
add_executable(main main.cpp)
target_link_libraries(main ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} sdlwrapper_lib TypeRight_lib Collision_lib)

###########
# Testing #
###########
add_subdirectory(gtest)


# Include gtest library
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(main_unittests main_unittests.cpp)
target_link_libraries(main_unittests sdlwrapper_lib gtest gtest_main SpriteFactory_lib Bruh_lib Lightsaber_lib Hero_lib Fireball_lib Dragon_lib Pegasus_lib Level_lib Collision_lib)

add_test(main_unittests main_unittests)

set(CMAKE_BUILD_TYPE Debug)
