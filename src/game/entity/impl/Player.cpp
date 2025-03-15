#include "Player.h"

#include <iostream>

#include "game/object/impl/Platform.h"


Player::Player(float x, float y)
{
    this->position.x = x;
    this->position.y = y;
    this->size.x = static_cast<float>(this->sprite->width);
    this->size.y = static_cast<float>(this->sprite->height);
    speed = 1;
}

#define WindowWidth (int) 1280
#define WindowHeight (int) 720

void Player::update(const int& ticks, const std::vector<Platform*>& platforms)
{
    this->velocity = Vec2_f();
    
    if (this->isFalling && this->jumpTimer <= 0)
    {
        if (this->fallTime < 3.f)
            this->fallTime += 0.1f;
        

        this->velocity.y += this->fallSpeed * this->fallTime;
    }
    
    if (IsKeyDown(KEY_UP))
    {
        if (this->canJump)
        {
            this->fallTime = 0.2f;
            this->velocity.y = -75.f;
            this->jumpTimer = 40;
        }
    }
    
    if (IsKeyDown(KEY_LEFT))
        this->velocity.x = -1.2f;
    if (IsKeyDown(KEY_RIGHT))
        this->velocity.x = 1.2f;
    


    if (this->jumpTimer > 0)
        this->jumpTimer--;
    
    this->updatePosition(platforms);
    this->clipInbounds();
}


void Player::updatePosition(const std::vector<Platform*>& platforms)
{
    float newX = this->position.x + (this->velocity.x * this->speed);
    float newY = this->position.y + (this->velocity.y * this->speed);

    bool collidedX = false;
    bool collidedY = false;
    for (auto p : platforms) {
        if (newX < p->position.x - p->size.x &&
            newX + this->size.x > p->position.x)
        {
            collidedX = true;
        }
       
        if (newY < p->position.y + p->size.y &&
            newY + this->size.y > p->position.y)
        {
            collidedY = true;
            this->canJump = true;
        }else
        {
            this->canJump = false;
        }
            

        //std::cout << "Collided: " << collidedX << ", " << collidedY << std::endl;
    }

    //lerp(collidedX, collidedY);
    if (!collidedX)
        this->position.x += this->velocity.x * this->speed;
    if (!collidedY)
        this->position.y += this->velocity.y * this->speed;
}



void Player::render(const int& ticks)
{
    this->updateRenderPosition();
    DrawTexture(this->sprite->getResource(), this->renderPosition.x, this->renderPosition.y, WHITE);
}

void Player::updateRenderPosition()
{
    this->renderPosition.x = (int)this->position.x;
    this->renderPosition.y = (int)this->position.y;
}

void Player::clipInbounds()
{
    if (((int)this->position.x + this->sprite->width) > WindowWidth)
        this->position.x = (float) (WindowWidth - this->sprite->width);
    if (((int)this->position.y + this->sprite->height) > WindowHeight)
        this->position.y = (float) (WindowHeight - this->sprite->height);
    this->position.y = std::max<float>(this->position.y, 0);
    this->position.x = std::max<float>(this->position.x, 0);
}
