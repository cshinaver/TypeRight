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
                        cout << "left keypress detected " << endl;
                        onRight = 0;
                        onLeft = 1;
                        break;
                    case SDLK_RIGHT: // right is highlighted
                        cout << "right keypress detected " << endl;
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
    sw.displayImage("inputBox.png", SCREEN_WIDTH / 7, SCREEN_HEIGHT / 2, 0, SCREEN_HEIGHT/11, 1, 0x67, 0xc8, 0xff );
    sw.displayImage("inputBox.png", SCREEN_WIDTH*4/7, SCREEN_HEIGHT / 2, 0, SCREEN_HEIGHT/11, 1, 0xf1, 0xfb, 0xfc ); 

    // displays quit and play strings
    sw.displayText("TypeRight", SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3.5, 50);
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
    if (quitActivation){
        cout << "User quits the game." << endl;
    }   
    else { // play is activated
        cout << "User plays the game." << endl;
    }
}
