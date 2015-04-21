/*
 * LevelMenu.cpp
 * Madelyn Nelson
 * Menu Class implementation
*/

#include "LevelMenu.h"
#include "SpriteFactory.h"

LevelMenu::LevelMenu(SDLWrapper &sw) : Level(sw)
{
    cout << " Level Menu is called here!!" << endl;
    /*
     * Default constructor
    */
    
    /* ####################SETUP BACKGROUND ################ */ 
    Background *background = new Background();
    background->setTexturePath("typeRightBackground1Double.png");
//    background->setTexturePath("menublue.png");

    setBackground(background);
    cout << "end of level menu constructor" << endl;
    /* ##################SET ALLOWED SPRITES############### */
    vector<SpriteType> vs;
    vs.push_back(TSkeleton);
/*
    vs.push_back(TSnail);
    vs.push_back(TCat);
    vs.push_back(TBruh);
*/
    SpriteFactory *_sf = new SpriteFactory(100, vs, "level2.txt", SCREEN_WIDTH, SCREEN_HEIGHT);

    setFactory(_sf);
    
}

void LevelMenu::generateSprites()
{
    /*
     * Handles sprite generation
    */

    Sprite *s = NULL;
    SpriteFactory *sf = getFactory();
    s = sf->generateSprites();

    // Check if new sprite added
    if (s != NULL)
    {
        addSprite(s);
    }

}

int LevelMenu::startLevel()
{
    /*
     * Starts level
     */
    cout << "start level method is entered" << endl;
    return Level::startLevel(1);
}
