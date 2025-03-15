#pragma once
#include <cstring>
#include <functional>

#include "raylib.h"
#include "engine/render/Screen.h"

class Button
{
private:
    Screen* screen = NULL;
    std::function<void()> callback = nullptr;
public:
    const char* text;
    int x, y;
    float textSize;

    Button(const char* text, int x, int y, float textSize, Screen* screen);
    Button(const char* text, int x, int y, float textSize, std::function<void()> callback, Screen* screen);
    void render();
    void update();
};
