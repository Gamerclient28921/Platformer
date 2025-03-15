#include "Platform.h"

#include "raylib.h"


void Platform::render(const int& ticks)
{
    this->renderLocation.position.x = (int)this->position.x;
    this->renderLocation.position.y = (int)this->position.y;
    this->renderLocation.size.x     = (int)this->size.x;
    this->renderLocation.size.y     = (int)this->size.y;

    DrawRectangle(this->renderLocation.getX(), this->renderLocation.getY(), renderLocation.getWidth(), renderLocation.getHeight(), GREEN);
}
