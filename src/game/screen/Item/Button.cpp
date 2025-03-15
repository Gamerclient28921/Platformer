#include "Button.h"


Button::Button(const char* text, int x, int y, float textSize, Screen* screen)
{
    this->text = text;
    this->x = x;
    this->y = y;
    this->textSize = textSize;
    this->screen = screen;
}

Button::Button(const char* text, int x, int y, float textSize, std::function<void()> callback, Screen* screen)
{
    this->text = text;
    this->x = x;
    this->y = y;
    this->textSize = textSize;
    this->callback = callback;
    this->screen = screen;
}


void Button::render()
{
    DrawRectangle(x - 5, y - 5, (int)(strlen(text)) * 8.5f, textSize * 2, GRAY);
    screen->DrawText(text, x, y, textSize, BLACK);
}

void Button::update()
{
    callback();
}
