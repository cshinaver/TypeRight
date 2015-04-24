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
}

void Menu::handleKeyboardEvents()
{
    SDL_Event e;

    SDL_StartTextInput();

    while (SDL_PollEvent( &e ) != 0)
    {
        switch (e.type)
        {
            case SDL_QUIT:
                break;
            case SDL_TEXTINPUT:
//                userInput = e.text[0];
                break;

        }
    }
}

int Menu::checkForPlayActivation()
{
    return 1;
}

void Menu::display() const
{
    sw.clearWindow();
    // displays background image
    sw.displayImage("inputBox.png", SCREEN_WIDTH / 7, SCREEN_HEIGHT / 2, 0, SCREEN_HEIGHT/11, 0, 0x67, 0xc8, 0xff );
    sw.displayImage("inputBox.png", SCREEN_WIDTH*4/7, SCREEN_HEIGHT / 2, 0, SCREEN_HEIGHT/11, 1, 0xf1, 0xfb, 0xfc );

    // displays quit and play strings
    sw.displayText("PLAY", SCREEN_WIDTH / 6, SCREEN_HEIGHT / 2, 40);
    sw.displayText("QUIT", SCREEN_WIDTH*4/6, SCREEN_HEIGHT / 2, 40);

    // updates screen
    sw.updateWindow();
}

void Menu::menuPlay()
{
    int count=0;
    sw.clearWindow();
    while (count<200)
    {
        display();
        count++;
    }
}
