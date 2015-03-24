/*
 * Level.h
 * Charles Shinaver
 * Level Class
*/

#include "Background.h"
class Level
{
    public:
        virtual void startLevel() = 0;
    private:
        Background levelBackground;
};
