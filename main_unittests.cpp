/*
 * main_unittests.cpp
 * Charles Shinaver
 * Main testing file
*/

#include "SDLWrapper.h"
#include "gtest/include/gtest/gtest.h"
#include <stdexcept>
#include "Bruh.h"

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

// Test texture not loaded returns zero when not loaded
TEST(SpriteTest, IsSpriteNotLoaded) {
    Bruh b;
    int ans = b.getIsTextureLoaded();
    ASSERT_TRUE(ans == 0);
}

// Test loaded texture in sprite says loaded
TEST(SpriteTest, IsSpriteLoaded) {
    SDLWrapper sw;
    sw.init();
    Bruh b;
    b.setTexture(sw.loadTexture("pirate.png"));
    int ans = b.getIsTextureLoaded();
    ASSERT_TRUE(ans == 1);
}

// SDLWrapper doesn't load texture if sprite doesn't have a loaded texture
TEST(SpriteTest, SDLWrapperDoesNotLoadSpriteIfNoTextureLoaded)
{
    SDLWrapper sw;
    sw.init();
    Bruh b;
    int SDLWrapperTextureLoadProperlyFailed = 0;
    try
    {
        sw.loadSprite(&b);
    }
    catch (const std::logic_error& e)
    {
        SDLWrapperTextureLoadProperlyFailed = 1;
    }
    ASSERT_TRUE(SDLWrapperTextureLoadProperlyFailed == 1);
}
