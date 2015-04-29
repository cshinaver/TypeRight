// menu.cpp

#include <iostream>
#include "menu.h"
#include <stdexcept>


using namespace std;

Menu::Menu(SDLWrapper &_sw)
    : SCREEN_WIDTH(_sw.SCREEN_WIDTH), 
    SCREEN_HEIGHT(_sw.SCREEN_HEIGHT),
    sw(_sw)
{   
    playActivation = 0; 
    quitActivation = 0;
    onLeft = 0;
    onRight = 0;
}

void Menu::handleKeyboardEvents()
{
    SDL_Event e;

    SDL_StartTextInput();

    while (SDL_PollEvent( &e ) != 0)
    {
        switch (e.type) // looks for keypress
        {
            case SDL_KEYDOWN: 
                switch ( e.key.keysym.sym ) // checks which was pressed
                {
                    case SDLK_LEFT: // left is highlighted
                        onRight = 0;
                        onLeft = 1;
                        break;
                    case SDLK_RIGHT: // right is highlighted
                        onLeft = 0;
                        onRight = 1;
                        break;
                    case SDLK_RETURN: // user presses enter
                        if (onLeft == 1) { // if play is highlighted
                            playActivation = 1; // plays game
                        }
                        else if (onRight == 1){ // quit is hightlighted
                            quitActivation = 1; // quits game
                        }
                        break;
                }
            break;
        }
    }
}

int Menu::getPlayActivation()
{
    return playActivation;
}

void Menu::display() const
{
    sw.clearWindow();
    
    // displays background image
    sw.displayImage("blueMenu.png", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    // displays moving red box around selected button
    if (onLeft)
    {
        sw.displayImage("redMenu2.png", SCREEN_WIDTH*.12, SCREEN_HEIGHT *.485);
    }
    else if(onRight)
    {
        sw.displayImage("redMenu2.png", SCREEN_WIDTH*.55, SCREEN_HEIGHT*.485);
    }
    
    // displays white button
    sw.displayImage("inputBox.png", SCREEN_WIDTH / 7, SCREEN_HEIGHT / 2, 0, SCREEN_HEIGHT/11, 1, 0xf1, 0x0b, 0xc3 );
    sw.displayImage("inputBox.png", SCREEN_WIDTH*4/7, SCREEN_HEIGHT / 2, 0, SCREEN_HEIGHT/11, 1, 0xf1, 0x0b, 0xc3 ); 

    // display hero sprite
    sw.displayImage("hero.png", SCREEN_WIDTH * .6, SCREEN_HEIGHT*.23, 0, 100, 1, 0xff, 0x00, 0xff );

    // displays quit and play strings
    sw.displayText("TypeRight", SCREEN_WIDTH*.2, SCREEN_HEIGHT / 3.8, 50);
    sw.displayText("PLAY", SCREEN_WIDTH*.25, SCREEN_HEIGHT*.49, 35);
    sw.displayText("QUIT", SCREEN_WIDTH*4/6, SCREEN_HEIGHT*.49, 35);
    sw.displayText("Charles Shinaver, Jared Rodgers, Elliott Runburg, Madelyn Nelson", SCREEN_WIDTH / 27, SCREEN_HEIGHT*.73, 20);
    

    // updates screen
    sw.updateWindow();
}

void Menu::menuPlay()
{
    sw.clearWindow();
    while (!playActivation && !quitActivation)
    {
        handleKeyboardEvents();        
        display();
    }
}
