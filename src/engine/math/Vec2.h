#pragma once

class Vec2_i {
public:
    int x, y;

    Vec2_i operator*(float other)
    {
        this->x = (int)((float)this->x * other);
        this->y = (int)((float)this->y * other);
        return *this;
    }
    
    Vec2_i operator+=(Vec2_i b)
    {
        this->x = this->x + b.x;
        this->y = this->y + b.y;
        
        return *this;
    }
    
    Vec2_i operator-=(Vec2_i  b)
    {
        this->x = this->x - b.x;
        this->y = this->y - b.y;
        
        return *this;
    }
};