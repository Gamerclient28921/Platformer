#include "Level.h"



void Level::init()
{
    Platform* platform = new Platform(200, 500, 200, 40);

    platforms.push_back(platform);
    this->player = new Player(0, 0);
}


void Level::update(const int& ticks)
{
    
    player->update(ticks, platforms);
    
}


void Level::render(const int& ticks)
{
    player->render(ticks);
    
    for (size_t i = 0; i < platforms.size(); i++)
    {
        platforms[i]->render(ticks);
    }
}
