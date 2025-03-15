#pragma once
#include "level/Level.h"
#include "screen/impl/GameScreen.h"
#include "game/entity/impl/Player.h"
#include "game/level/Level.h"
#include "game/screen/impl/GameScreen.h"
#include "game/screen/impl/MenuScreen.h"
#include "engine/assets/ResourceLocation.h"
#include "engine/render/Screen.h"



class Game
{
private:
    Font roboto;
    
    int ticks = 0;
public:
    Screen* currentScreen;
    Level* currentLevel;
    
    Game()
    {
        roboto = LoadFont("../res/Font/Roboto.ttf");

        
        currentScreen = new MenuScreen(roboto);
        currentLevel  = new Level();
    }


    void render();
    void update();
    Font getFont() { return roboto; }
};

static Game* game = new Game();