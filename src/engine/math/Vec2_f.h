#pragma once

class Vec2_f
{
public:
    float x, y = 0.f;

    Vec2_f()
    {
        this->x = 0.f;
        this->y = 0.f;
    }
    Vec2_f(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    Vec2_f(float value)
    {
        this->x = value;
        this->y = value;
    }

    Vec2_f operator+(const Vec2_f& other)
    {
        return Vec2_f(this->x + other.x, this->y + other.y);
    }
    Vec2_f operator-(const Vec2_f& other)
    {
        return Vec2_f(this->x - other.x, this->y - other.y);
    }
    Vec2_f operator*(const Vec2_f& other)
    {
        return Vec2_f(this->x * other.x, this->y * other.y);
    }
    Vec2_f operator/(const Vec2_f& other)
    {
        return Vec2_f(this->x / other.x, this->y * other.y);
    }

    
    Vec2_f operator*(const float& other)
    {
        return Vec2_f(this->x * other, this->y * other);
    }
    Vec2_f operator/(const float& other)
    {
        return Vec2_f(this->x / other, this->y / other);
    }

    Vec2_f operator+=(const Vec2_f& other)
    {
        return Vec2_f(this->x + other.x, this->y + other.y);
    }
    Vec2_f operator-=(const Vec2_f& other)
    {
        return Vec2_f(this->x - other.x, this->y - other.y);
    }
    Vec2_f operator*=(const Vec2_f& other)
    {
        return Vec2_f(this->x * other.x, this->y * other.y);
    }
    Vec2_f operator/=(const Vec2_f& other)
    {
        return Vec2_f(this->x / other.x, this->y / other.y);
    }
    

    Vec2_f expand(const Vec2_f& other)
    {
        return Vec2_f(this->x + other.x, this->y + other.y);
    }

    
};