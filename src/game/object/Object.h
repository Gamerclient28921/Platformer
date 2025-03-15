#pragma once

#include "engine/math/Rect.h"
#include "engine/math/Vec2_f.h"
#include "engine/math/Vec2_i.h"

class Object
{
private:
    Vec2_i renderPosition;
public:
    Vec2_f position;
    Vec2_f size;

    
    Rect getRect()
    {
        return {position, size};
    }
    
    void render(const int& ticks);
};
