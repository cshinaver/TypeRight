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
    ASSERT_TRUE(sw.init() == true);
}

// Test if bmp image loaded
TEST(SDLTest, IsBmpImageLoaded) {
    SDLWrapper sw;
    sw.init();
    SDL_Surface *img = sw.loadImg("hello_world.bmp");
    ASSERT_TRUE( img != NULL);
    SDL_FreeSurface(img);
}

// Test exception if image not loaded
TEST(SDLTest, IsBmpImageNotLoaded) {
    SDLWrapper sw;
    sw.init();
    int imgProperlyFailed = 0;
    try
    {
        sw.loadImg("non_existent_image.bmp");
    }
    catch (const std::runtime_error& e)
    {
        imgProperlyFailed = 1;
    }
    ASSERT_TRUE(imgProperlyFailed == 1);
}

// Load Texture Test
TEST(SDLTest, IsTextureLoaded) {
    SDLWrapper sw;
    sw.init();
    TRTexture img = sw.loadTexture("hello_world.bmp");
    ASSERT_TRUE( img.isTextureLoaded() == 1);
    img.freeTexture();
}
