#pragma once
#include "raylib.h"
#include "engine/assets/ResourceLocation.h"

#include "engine/math/Vec2_f.h"
#include "engine/math/Vec2_i.h"

class Player
{
private:
    ResourceLocation* sprite;
    float fallSpeed = 0.6f;
    float fallTime = 0.0f;
    bool isFalling = true;

    Vec2_i renderPosition;
    
    void clipInbounds();
    void updateRenderPosition();
public:
    Vec2_f position;
    Vec2_f velocity;
    float speed;
    
    Player(int, int, ResourceLocation*);

    void update(int& ticks);
    
    void render();
    bool checkCollisionHorizontal(const Vector2&);
    void updatePosition();

    
};

