#include "GameOver.h"
#include <stdexcept>
#include <iostream>
#include <ctime>

using namespace std;

GameOver::GameOver(SDLWrapper &_sw) : Level(_sw, "", 0), SCREEN_WIDTH(_sw.SCREEN_WIDTH), SCREEN_HEIGHT(_sw.SCREEN_HEIGHT), sw(_sw)
{
    Background *background = new Background();
    background->setTexturePath("game_over_background.png");

    setBackground(background);
}

void GameOver::display() const
{
    sw.clearWindow();

    sw.displayImage("game_over_background.png", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    sw.displayText("GAME OVER", SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3, 50);

    if ( selected )
	sw.displayImage("inputBox.png", SCREEN_WIDTH / 7, SCREEN_HEIGHT / 2, 0, SCREEN_HEIGHT/11, 1);
    else
	sw.displayImage("inputBox.png", SCREEN_WIDTH*4/7, SCREEN_HEIGHT / 2, 0, SCREEN_HEIGHT/11, 1);


    sw.displayText("PLAY", SCREEN_WIDTH*.25, SCREEN_HEIGHT*.49, 35);
    sw.displayText("QUIT", SCREEN_WIDTH*4/6, SCREEN_HEIGHT*.49, 35);

    sw.updateWindow();
}

int GameOver::handleKeyboardEvents()
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
                        selected = 1; // Play again
			break;
                    case SDLK_RIGHT: // right is highlighted
                        selected = 0; // Quit
                        break;
                    case SDLK_RETURN: // user presses enter
                        return selected; // Returns play or quit
			break;
                }
            break;
        }
    }
    return 2;
}

int GameOver::gameOverPlay()
{
    int choice;
    selected = 1;
    while ( 1 ) {
	display();
	choice = handleKeyboardEvents();
	if ( choice != 2 )
	    break;
    }    

    return choice;
}
