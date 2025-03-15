#pragma once
#include <vector>

#include "raylib.h"

#include "engine/render/Screen.h"
#include "./game/screen/Item/Button.h"

class MenuScreen : public Screen
{
private:
    std::vector<Button> buttons;
public:
    MenuScreen(const Font& font) : Screen(font)
    {
        this->type = ScreenType::MenuScreen;
        this->init();
    }

    void init();
    void render(const int& ticks);
    void update(const int& ticks);
};
