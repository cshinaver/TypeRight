/*
 * TypeRight.cpp
 * Charles Shinaver + Jared Rodgers
 * Main game implementation
*/

#include "TypeRight.h"
#include "Bruh.h"
#include "Background.h"
#include "Soldier.h"
#include "Skeleton.h"
#include "Cat.h"
#include "Snail.h"
#include "SpriteFactory.h"

void backgroundDemoFunction(SDLWrapper &sw);

TypeRight::TypeRight()
{
    /*
     * Default constructor
    */

    bgX=0; // background starts at beginning, leftmost x coordinate of texture
    bgY=0; // doesn't change

    // Init window and initial surface
    sw.init();

    //initializes textures
    backgroundTex = sw.loadTexture("typeRightBackground1Double.png", 0, 0, 0xFF, 0xFF);
}

void TypeRight::startGame()
{
    /*
     * Starts game
    */


    // Set quit status
    quit = false;

    //##################
    //# Main Game Loop #
    //##################

//    Background backk(sw.loadTexture("background3.png")); // mysterious blue+purple
//   Background backk(sw.loadTexture("typeRightBackground1Double.png")); // original, field and sky
//   Background backk(sw.loadTexture("background4.png")); // morris inn
//   Background backk(sw.loadTexture("background5.png")); // city at night
//   Background backk(sw.loadTexture("background6.png")); // purple forrest
//    Background backk(sw.loadTexture("background2.png")); // gross USA map
    
    Background *back = new Background;
    sprites.push_back(back);
    
    Bruh *b = new Bruh;
    b->setPos(100, 100);
    Soldier *sol = new Soldier;
    sol->setPos(200, 100);
    Skeleton *skel = new Skeleton;
    skel->setPos(300, 100);
    Snail *sna = new Snail;
    sna->setPos(400, 100);
    Cat *c = new Cat;
    c->setPos(250,250);
    sprites.push_back(c);
    sprites.push_back(b);
    sprites.push_back(sol);
    sprites.push_back(skel);
    sprites.push_back(sna);

    // For demo
    SpriteFactory sf;
    
    /* Demo purposes */
    int demoSpriteGenerated = 0;
    /* ############# */
    while (!quit)
    {
        // Check for keyboard events
        checkForEvents();

        // Generate sprites
        if (!demoSpriteGenerated)
        {
            Sprite *s1 = sf.getSprite(0); // Make enums
            Sprite *s2 = sf.getSprite(1);
            s2->setPos(300, 50);
            sprites.push_back(s1);
            sprites.push_back(s2);
            demoSpriteGenerated = 1;
        }

        // Clear screen
        SDL_SetRenderDrawColor(sw.renderer, 0xFF, 0xFF, 0xFF, 0xFF );        
        sw.clearWindow();

        // Load and move every sprite
        for (vector<Sprite *>::iterator i = sprites.begin(); i != sprites.end(); i++)
        {
            sw.loadSprite(*i);
            (*i)->move();
        }

        // Update screen
        sw.updateWindow();
    }

    // Free all textures
    for (vector<Sprite *>::iterator i = sprites.begin(); i != sprites.end(); i++)
    {
        (*i)->destroySprite();
        delete (*i);
    }
    
    // Quit SDL
    sw.quit();

    // Free textures
    backgroundTex.freeTexture();
}

void TypeRight::checkForEvents()
{
    /*
     * Checks for any events in queue and responds if any
     * Put responses to events here
    */

    // Event handler
    SDL_Event e;

    // Event handler loop
    while (SDL_PollEvent( &e ) != 0)
    {
        // User quits
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }
    }
}

void backgroundDemoFunction(SDLWrapper &sw)
{
    /*
     * Similar to demoFunction above, except with background1 this time
    */
/*
    TRTexture back = sw.loadTexture("typeRightBackground1.png"); // new background
    sw.renderTextureToWindow(back);
    TRTexture foo = sw.loadTexture("foo.png", 1, 0, 0xFF, 0xFF);
    SDL_Rect renderQuad = {sw.SCREEN_WIDTH / 2, sw.SCREEN_HEIGHT / 2, foo.getWidth(), foo.getHeight()};
    sw.renderTextureToWindow(foo, NULL, &renderQuad);
*/
}

