#pragma once
#include "Vec2_f.h"

class Rect
{
public:
    Vec2_f position;
    Vec2_f size;

    Rect()
    {
        position = Vec2_f(0, 0);
        size = Vec2_f(0, 0);
    }
    Rect(Vec2_f position, Vec2_f size)
    {
        this->position = position;
        this->size = size;
    }
    Rect(Vec2_f value)
    {
        this->position = value;
        this->size = value;
    }
    Rect(float x, float y, float width, float height)
    {
        this->position = Vec2_f(x, y);
        this->size = Vec2_f(width, height);
    }


    float getX()
    {
        return this->position.x;
    }
    float getY()
    {
        return this->position.y;
    }
    float getWidth()
    {
        return this->position.x + this->size.x;
    }
    float getHeight()
    {
        return this->position.y + this->size.y;
    }
};
