#include "Game.h"


void Game::update()
{
    if (IsKeyDown(KEY_F3))
        currentScreen->renderDebugMenu = !currentScreen->renderDebugMenu;

    currentLevel->update(ticks);

    ticks++;
}

void Game::render()
{
    if (currentScreen->type == ScreenType::GameScreen)
    {
        GameScreen* game_screen = static_cast<GameScreen*>(currentScreen);
			
        game_screen->render(*currentLevel->player, ticks);

        ClearBackground(BLUE);
        currentLevel->render(ticks);
    }
}