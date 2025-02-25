#pragma once
#include "raylib.h"

#include "engine/assets/ResourceLocation.h"
#include "engine/math/Vec2.h"

class Player
{
private:
    ResourceLocation* sprite;
    float fallSpeed = 0.6f;
    float fallTime = 0.0f;
    bool isFalling = true;
    

    const void clipInbounds();
public:
    Vec2_i position;
    Vec2_i velocity;
    float speed;
    
    Player(int, int, ResourceLocation*);

    void update(int& ticks);
    void render();
    const bool checkCollisionHorizontal(const Vector2&);
    const void updatePosition();

    
};

