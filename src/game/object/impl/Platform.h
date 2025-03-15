#pragma once

#include "engine/math/Vec2_f.h"
#include "engine/math/Vec2_i.h"
#include "engine/math/Rect.h"

class Platform
{
private:
    Rect renderLocation;
public:
    Vec2_f position;
    Vec2_f size;
    
    Platform(float x, float y, float width, float height)
    {
        this->position = {x, y};
        this->size     = {width, height};
    }
    
    void render(const int& ticks);
    void update(const int& ticks);
};
