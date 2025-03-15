#pragma once
#include "raylib.h"
#include "engine/render/Screen.h"

class MenuScreen : Screen
{
public:
    MenuScreen(const Font& font) : Screen(font)
    {
        this->type = ScreenType::MenuScreen;
    }

    const void render(const int& ticks);
};
