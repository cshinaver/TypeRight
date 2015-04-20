/*
 * SpriteFactory.cpp
 * Charles Shinaver
 * Sprite Factory class implementation
*/

#include "SpriteFactory.h"
#include <stdlib.h>
#include <time.h>

vector<string> loadWordsFromFile(string filePath);

SpriteFactory::SpriteFactory(
        int _generationFrequency,
        vector<enum SpriteType>_allowedSprites,
        string wordBankFilepath,
        int _SCREEN_WIDTH,
        int _SCREEN_HEIGHT
        ) : 
    allowedSprites(_allowedSprites),
    generationFrequency(_generationFrequency),
    SCREEN_WIDTH(_SCREEN_WIDTH),
    SCREEN_HEIGHT(_SCREEN_HEIGHT)
{
    /*
     * Default constructor
    */

    // Seed rand
    srand(time(NULL));

    // Set words
    wordBank = loadWordsFromFile(wordBankFilepath);
    count = 0;
}

Sprite * SpriteFactory::getSprite(int typeDesired)
{
    /*
     * Returns sprite pointer based on input
    */
    
    Sprite *s = new Bruh;
    return s;
}

Sprite * SpriteFactory::generateSprites()
{
    // Counts frames and generates based on frame number
    Sprite *s = NULL;
    int chosenSpriteIndex, chosenWordIndex;
    SpriteType chosenSprite;
    string chosenWord;

    // Get random sprite
    if (!(count % generationFrequency) && count != 0)
    {
        // Get random sprite
        chosenSpriteIndex = rand() % allowedSprites.size();
        chosenSprite = allowedSprites[chosenSpriteIndex];
        
        // Get random word
        chosenWordIndex = rand() % wordBank.size();
        chosenWord = wordBank[chosenWordIndex];

        // Select sprite to give
        switch (chosenSprite)
        {
            case TCat:
                s = new Cat;
                s->setFlip(1);
                break;
            case TSkeleton:
                s = new Skeleton;
                s->setFlip(1);
                break;
            case TSoldier:
                s = new Soldier;
                s->setFlip(1);
                break;
            case TBruh:
                s = new Bruh;
                s->setFlip(1);
                break;
            case TSnail:
                s = new Snail;
                s->setFlip(1);
                break;
            case TSlowDownPowerup:
                s = new SlowDownPowerup;
                break;
        }

        // Set text
        s->setText(chosenWord);

        // Set default sprite settings
        setDefault(s);
        count = 0;
    }
    else
    {
        count++;
    }

    return s;
}

void SpriteFactory::setDefault(Sprite * _s)
{
    /*
     * Sets sprite default characteristsics
    */

    _s->setPos(SCREEN_WIDTH * 19./20, SCREEN_HEIGHT * .625);
    _s->setSize(100, 100);

}

vector<string> loadWordsFromFile(string filePath)
{
    /*
     * Loads words from given file
     * NOTE: filePath needs to only be the name of the text file in the words
     * directory of the project. 
     * Eg. for the word file "level1.txt",
     * the filepath should be the string "level1.txt"
    */

    string line;
    vector<string> wordBank;
    string fullFilePath = "../words/" + filePath;
    ifstream fin(fullFilePath.c_str());
    if (fin.is_open())
    {
        while(getline(fin, line))
        {
            wordBank.push_back(line);
        }
        fin.close();
    }
    else
    {
        throw runtime_error("Word file could not be opened");
    }

    return wordBank;
}

