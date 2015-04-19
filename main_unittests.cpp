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
#include "Collision.h"
#include "Level.h"

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

TEST(SpriteTest, SpriteGeneratedFromFactory)
{
    SDLWrapper sw;
    sw.init();
    
    vector<SpriteType> vs;
    vs.push_back(TCat);
    SpriteFactory sf(1, vs, 640, 480);
    Sprite *s;
    s = NULL;
    s = sf.generateSprites();
    s = sf.generateSprites();
    ASSERT_TRUE(s != NULL);
    sw.loadSprite(s);
    ASSERT_TRUE(s->getIsTextureLoaded() == 1);
}

// Sprite only generated every 40 frames
TEST(SpriteTest, SpriteGeneratedOnCertainFrequency)
{
    SDLWrapper sw;
    sw.init();
    int frame = 0;
    int generateFrame = 40;
    
    vector<SpriteType> vs;
    vs.push_back(TCat);
    SpriteFactory sf(generateFrame, vs, 640, 480);
    Sprite *s;
    s = NULL;


    while (frame != generateFrame)
    {
        s = sf.generateSprites(); 
        ASSERT_TRUE(s == NULL);
        frame++;
    }

    // Once 40, sprite should be generated
    s = sf.generateSprites(); 
    ASSERT_TRUE(s != NULL);

    sw.loadSprite(s);
    ASSERT_TRUE(s->getIsTextureLoaded() == 1);
}

TEST(SpriteTest, SpriteCollidesWithHero)
{
    // Inst sprites
    Bruh *b = new Bruh;
    Skeleton *s = new Skeleton;
    Background *background = new Background();

    // Set Hero
    b->setIsHero();

    // set sizes
    b->setSize(30, 30);
    s->setSize(30, 30);

    // Store in vector
    vector<Sprite *> vs;
    vs.push_back(background);
    vs.push_back(b);
    vs.push_back(s);

    // Set skeleton as same position as hero
    b->setPos(50, 50);
    s->setPos(50, 50);

    // Collision detection
    Collision cd = Collision(&vs);

    // Check if hero is dead
    cd.isDead();
    ASSERT_TRUE(cd.isDead() == 1);

    delete b;
    delete s;
    delete background;
}
