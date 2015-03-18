/*
 * TypeRight.cpp
 * Charles Shinaver
 * Main game implementation
 */

#include "TypeRight.h"
#include "Bruh.h"

void demoFunction(SDLWrapper &sw);
void backgroundDemoFunction(SDLWrapper &sw);

TypeRight::TypeRight()
{
	/*
	 * Default constructor
	 */
	bgX=0; // background starts at beginning, leftmost x coordinate of texture
	bgY=0;
	
	//initializes textures
	TRTexture back = sw.loadTexture("typeRightBackground1.png"); // new background
	sw.renderTextureToWindow(back);

	TRTexture background = sw.loadTexture("typeRightBackground1.png", 0, 0, 0xFF, 0xFF);
//	TRTexture foo = sw.loadTexture("foo.png", 1, 0, 0xFF, 0xFF);
}

void TypeRight::startGame()
{
	/*
	 * Starts game
	 */

	// Init window and initial surface
	sw.init();

	// Set quit status
	quit = false;

	//##################
	//# Main Game Loop #
	//##################

	// For demo
	int count=0;
	while (!quit)
	{
		checkForEvents();

		// Clear screen
		SDL_SetRenderDrawColor(sw.renderer, 0xFF, 0xFF, 0xFF, 0xFF );        
		sw.clearWindow();

		//demoFunction(sw);
		//backgroundDemoFunction(sw); // tests the new background
		cout << "count=" << count << endl; // counts while loop iterations
		count++;

		//Scroll Background is somewhere near here???????
		scrollBackground();

		// Update screen
		sw.updateWindow();
	}

	// Quit SDL
	sw.quit();
}

void TypeRight::scrollBackground()
{
	// Offset of the background
	bgX+=10; 
	if (bgX >= 900 ) // background1 is 951 x 521 pixels, shouldn't hard code this. FIX LATER!!
	{
		bgX=0; // reset to the beginning of the background
	}	
	cout << "bgX=" << bgX << endl;

// destination rectangle
	SDL_Rect src = {bgX, bgY, background.getWidth(), background.getHeight()};
	SDL_Rect dest = {0, 0, sw.SCREEN_WIDTH, sw.SCREEN_HEIGHT};
//	SDL_Rect renderQuad2 = {sw.SCREEN_WIDTH / 2, sw.SCREEN_HEIGHT / 2, foo.getWidth(), foo.getHeight()};
	//apply_surface(bgX, bgY, back, screen);

//	sw.renderTextureToWindow(foo, NULL, &renderQuad2);
	sw.renderTextureToWindow(background, &src, &dest);

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

void demoFunction(SDLWrapper &sw)
{
    /*
     * For demo purproses
    */

    Bruh b(sw.loadTexture("pirate.png", 1, 0x20, 0xB5, 0x62));
    sw.loadSprite(&b);
}

void backgroundDemoFunction(SDLWrapper &sw)
{
	/*
	 * Similar to demoFunction above, except with background1 this time
	 */

	TRTexture back = sw.loadTexture("typeRightBackground1.png"); // new background
	sw.renderTextureToWindow(back);
	TRTexture foo = sw.loadTexture("foo.png", 1, 0, 0xFF, 0xFF);
	SDL_Rect renderQuad = {sw.SCREEN_WIDTH / 2, sw.SCREEN_HEIGHT / 2, foo.getWidth(), foo.getHeight()};
	sw.renderTextureToWindow(foo, NULL, &renderQuad);
}


