#pragma once
#include <raylib.h>

#include "game/entity/impl/Player.h"
#include "./engine/render/Screen.h"


class GameScreen : public Screen
{
public:
    GameScreen(const Font& font) : Screen(font)
    {
        this->type = ScreenType::GameScreen;
    }
    
    const void render(const Player&, const int&);
};
