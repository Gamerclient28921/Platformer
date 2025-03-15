#include "Game.h"


void Game::update()
{
    switch (currentScreen->type)
    {
    case ScreenType::GameScreen:
        
        if (IsKeyDown(KEY_F3))
            currentScreen->renderDebugMenu = !currentScreen->renderDebugMenu;
        
        currentLevel->update(ticks);
        break;
    case ScreenType::MenuScreen:
        MenuScreen* menu_screen = static_cast<MenuScreen*>(currentScreen);
        menu_screen->update(ticks);
        break;
    }
    ticks++;
}

void Game::render()
{
    ClearBackground(BLUE);
    if(currentScreen->type == ScreenType::GameScreen)
    {
        GameScreen* game_screen = static_cast<GameScreen*>(currentScreen);
			
        game_screen->render(*currentLevel->player, ticks);
        
        currentLevel->render(ticks);
    }
    else if(currentScreen->type == ScreenType::MenuScreen) {
        
        MenuScreen* menu_screen = static_cast<MenuScreen*>(currentScreen);
        menu_screen->render(ticks);
    }
}