// Background.cpp
#include "Background.h"

Background::Background()
{
    /* Default constructor*/

    setPos(0,0); // All backgrounds start at beginning
}

void Background::setTexturePath(string path)
{
    /*
     * Sets texture path
    */
    Sprite::setTexturePath(path);
}

void Background::setTexture(TRTexture tex)
{
    Sprite::setTexture(tex);
    vector<SDL_Rect> clips;
    setCurrentFrame(0);
    setTotalFrames(0);

    double backFract = .5; // fraction of whole background that is shown at any given moment
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
