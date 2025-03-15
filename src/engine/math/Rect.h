#pragma once
#include "Vec2_f.h"

class Rect
{
public:
    Vec2_i position;
    Vec2_i size;

    Rect()
    {
        position = Vec2_i(0, 0);
        size = Vec2_i(0, 0);
    }
    Rect(Vec2_i position, Vec2_i size)
    {
        this->position = position;
        this->size = size;
    }
    Rect(Vec2_i value)
    {
        this->position = value;
        this->size = value;
    }
    Rect(int x, int y, int width, int height)
    {
        this->position = Vec2_i(x, y);
        this->size = Vec2_i(width, height);
    }


    int getX()
    {
        return this->position.x;
    }
    int getY()
    {
        return this->position.y;
    }
    int getWidth()
    {
        return this->size.x;
    }
    int getHeight()
    {
        return this->size.y;
    }
};
