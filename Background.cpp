// Background.cpp
#include "Background.h"

Background::Background()
{
 /* Default constructor*/

//    setTexturePath("typeRightBackground1Double.png"); // country field
//    db = .3;

//    setTexturePath("background2.png"); // ugly usa map

//    setTexturePath("Combinedbackground3.png"); // mysterious purple moon
//    db = 1;

//    setTexturePath("background4.png"); // morris inn

//    setTexturePath("Combinedbackground5-4.png"); // night city, db=2
//    db = .5;

//    setTexturePath("Combinedbackground6.png"); // mysterious purple moon
//    db = .14;

//    setTexturePath("background7.png"); // world map 

//    setTexturePath("background8.png"); // castle

    setTexturePath("Combinedbackground9-9.png"); // mysterious purple moon
    db = .35;
}

void Background::setTexture(TRTexture tex)
{
    Sprite::setTexture(tex);
    vector<SDL_Rect> clips;
    setCurrentFrame(0);
    setTotalFrames(0);

//    int dt = 10; // used to be 3
    double backFract = .5; // fraction of whole background that is shown at any given moment
    int numFrames = tex.getWidth()*(1-backFract)*.5; // width of background
    // times 1-(fraction shown) times .5 times total background

    // Set background equal to second column sprites
    SDL_Rect frame;
    frame.x = 0;

    while ( frame.x < tex.getWidth()*.5 ) 
    {
        frame.w = tex.getWidth()*backFract;
        frame.h = tex.getHeight();
        frame.x += getDt()*db;
        frame.y = tex.getHeight()-540; // 540 for background3, 0 for background1 

        clips.push_back(frame);
    }
    
    setPos(0,0); // takes up whole screen, so this starts in top left corner
    setTextureClips(clips); 

//    setWidth(tex.getWidth()*backFract);
//    setHeight(tex.getHeight());
    setWidth(640);
    setHeight(480);
}

void Background::move()
{
    int tFrames = getTotalFrames();
    int speedConst = 1; // Modify this to make sprite animation faster or slower
    setCurrentFrame(tFrames / speedConst);
    tFrames++;
    setTotalFrames(tFrames);

    if (tFrames / speedConst >= (int)textureClips.size())
    {
        tFrames = 0;
        setTotalFrames(tFrames);
    }

}