/*
 * main_unittests.cpp
 * Charles Shinaver
 * Main testing file
*/

#include "SDLWrapper.h"
#include "gtest/include/gtest/gtest.h"
#include <stdexcept>
#include "Bruh.h"
#include "SpriteFactory.h"

// Test if window is instantiated
TEST(SDLTest, IsWindowCreated) {
    SDLWrapper sw;
    ASSERT_TRUE(sw.init() == true);
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

// Check that loadSprite can load a sprite from the spriteFactory
TEST(SpriteTest, LoadSpriteLoadsSpriteFromSpriteFactory)
{
    SDLWrapper sw;
    sw.init();
    
    vector<SpriteType> vs;
    vs.push_back(TCat);
    SpriteFactory sf(1, vs);
    Sprite *s;
    s = NULL;
    s = sf.generateSprites();
    ASSERT_TRUE(s != NULL);
    sw.loadSprite(s);
    ASSERT_TRUE(s->getIsTextureLoaded() == 1);
}

