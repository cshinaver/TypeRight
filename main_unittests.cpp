/*
 * main_unittests.cpp
 * Charles Shinaver
 * Main testing file
*/

#include "SDLWrapper.h"
#include "gtest/include/gtest/gtest.h"
#include <stdexcept>

// Test if window is instantiated
TEST(SDLTest, IsWindowCreated) {
    SDLWrapper sw;
    sw.init();
    ASSERT_TRUE(sw.window != NULL);
}

// Test if bmp image loaded
TEST(SDLTest, IsBmpImageLoaded) {
    SDLWrapper sw;
    sw.init();
    SDL_Surface *img = sw.loadBmpImg("hello_world.bmp");
    ASSERT_TRUE( img != NULL);
}

// Test exception if image not loaded
TEST(SDLTest, IsBmpImageNotLoaded) {
    SDLWrapper sw;
    sw.init();
    int imgProperlyFailed = 0;
    try
    {
        sw.loadBmpImg("non_existent_image.bmp");
    }
    catch (const std::runtime_error& e)
    {
        imgProperlyFailed = 1;
    }
    ASSERT_TRUE(imgProperlyFailed == 1);
}
