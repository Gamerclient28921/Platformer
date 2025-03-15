#pragma once

class Vec2_i
{
public:
    int x, y = 0.f;

    Vec2_i()
    {
        this->x = 0.f;
        this->y = 0.f;
    }
    Vec2_i(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Vec2_i(int value)
    {
        this->x = value;
        this->y = value;
    }

    Vec2_i operator+(const Vec2_i& other)
    {
        return {this->x + other.x, this->y + other.y};
    }
    Vec2_i operator-(const Vec2_i& other)
    {
        return {this->x - other.x, this->y - other.y};
    }
    Vec2_i operator*(const Vec2_i& other)
    {
        return {this->x * other.x, this->y * other.y};
    }
    Vec2_i operator/(const Vec2_i& other)
    {
        return {this->x / other.x, this->y * other.y};
    }

    
    Vec2_i operator*(const int& other)
    {
        return {this->x * other, this->y * other};
    }
    Vec2_i operator/(const int& other)
    {
        return {this->x / other, this->y / other};
    }

    Vec2_i operator+=(const Vec2_i& other)
    {
        return {this->x + other.x, this->y + other.y};
    }
    Vec2_i operator-=(const Vec2_i& other)
    {
        return {this->x - other.x, this->y - other.y};
    }
    Vec2_i operator*=(const Vec2_i& other)
    {
        return {this->x * other.x, this->y * other.y};
    }
    Vec2_i operator/=(const Vec2_i& other)
    {
        return {this->x / other.x, this->y / other.y};
    }

    Vec2_i operator!=(const Vec2_i& other)
    {
        return {this->x != other.x, this->y != other.y};
    }
    Vec2_i operator==(const Vec2_i& other)
    {
        return {this->x == other.x, this->y == other.y};
    }
};