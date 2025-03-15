#pragma once
#include <vector>

#include "game/object/impl/Platform.h"
#include "game/entity/impl/Player.h"


class Object;

class Level
{
public:
    Player* player = nullptr;
    std::vector<Platform*> platforms;
    
    Level()
    {
        init();
    }

    void init();
    void render(const int& ticks);
    void update(const int& ticks);
};
