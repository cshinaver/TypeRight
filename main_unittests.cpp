/*
 * main_unittests.cpp
 * Charles Shinaver
 * Main testing file
*/

#include "SDLWrapper.h"
#include "gtest/include/gtest/gtest.h"

// Test if window is instantiated
TEST(SDLTest, IsWindowCreated) {
    SDLWrapper sw;
    ASSERT_TRUE(sw.window != NULL);
}

// Test if bmp image loaded
TEST(SDLTest, IsBmpImageLoaded) {
    SDLWrapper sw;
    SDL_Surface *img = sw.loadBmpImg("hello_world.bmp");
    ASSERT_TRUE(sw.window != NULL);
}
