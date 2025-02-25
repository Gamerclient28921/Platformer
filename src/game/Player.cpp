#include "Player.h"



Player::Player(int x, int y, ResourceLocation* sprite)
{
    this->position.x = x;
    this->position.y = y;
    this->sprite = sprite;
    speed = 1;
}

#define WindowWidth (int) 1280
#define WindowHeight (int) 720

void Player::update(int& ticks)
{
    if (ticks % 20)
    {
        this->velocity.x = 0;
        this->velocity.y = 0;
    }
    if (this->position.y + this->sprite->height <= 0)
    {
        isFalling = false;
        this->fallTime = 0.0f;
    }
    
    if (isFalling)
    {
        if (fallTime <= 3)
            fallTime += 0.2f;
        

        this->velocity.y += fallSpeed * fallTime;
    }
    
    if (IsKeyDown(KEY_UP))
        this->velocity.y = -5.f;
    if  (IsKeyDown(KEY_DOWN))
        this->velocity.y = 1.2f;
    if (IsKeyDown(KEY_LEFT))
        this->velocity.x = -1.2f;
    if (IsKeyDown(KEY_RIGHT))
        this->velocity.x = 1.2f;


    updatePosition();
    this->clipInbounds();
    ticks++;
    
    
}



const bool Player::checkCollisionHorizontal(const Vector2& toCheck)
{
    if ((this->position.x >= toCheck.x && this->position.x <= toCheck.x) ||
        (this->position.x + this->sprite->width >= toCheck.x && this->position.x + this->sprite->width <= toCheck.x))
        return true;
    
    return false;
}

const void Player::updatePosition()
{
    this->position += this->velocity * this->speed;
}

void Player::render()
{
    DrawTexture(this->sprite->getResource(), this->position.x, this->position.y, WHITE);
}

const void Player::clipInbounds()
{
    if (((int)this->position.x + this->sprite->width) > WindowWidth)
        this->position.x = WindowWidth - this->sprite->width;
    if (((int)this->position.y + this->sprite->height) > WindowHeight)
        this->position.y = WindowHeight - this->sprite->height;
    this->position.y = std::max<int>(this->position.y, 0);
    this->position.x = std::max<int>(this->position.x, 0);
}
