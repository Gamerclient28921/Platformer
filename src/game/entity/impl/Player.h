#pragma once
#include <vector>

#include "raylib.h"
#include "engine/assets/ResourceLocation.h"

#include "engine/math/Vec2_f.h"
#include "engine/math/Vec2_i.h"
#include "game/object/impl/Platform.h"
class Player
{
private:
    
    ResourceLocation* sprite = new ResourceLocation("../res/PlayerSprite.png");;
    float fallSpeed = 0.6f;
    float fallTime = 0.0f;
    int jumpTimer = 0;
    bool isFalling = true;
    bool canJump = false;
    

    
    Vec2_i renderPosition;
    
    void clipInbounds();
    void updateRenderPosition();
public:
    Vec2_f position;
    Vec2_f size;
    Vec2_f velocity;
    float speed;
    
    Player(float, float);

    void update(const int& ticks, const std::vector<Platform*>& platforms);
    
    void render(const int& ticks);
    void updatePosition(const std::vector<Platform*>& platforms);

    
};

