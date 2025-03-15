#include "GameScreen.h"



const void GameScreen::render(const Player& player, const int& ticks)
{
    if (renderDebugMenu)
    {
        DrawText(("POS:      " + std::to_string(player.position.x) + ", " + std::to_string(player.position.y)).c_str(), 20, 20,  20, WHITE);
        DrawText(("Velocity: " + std::to_string(player.velocity.x) + ", " + std::to_string(player.velocity.y)).c_str(), 20, 44 , 20, WHITE);
        DrawText(("Ticks:    " + std::to_string(ticks)).c_str(), 20, 64, 20, WHITE);
    }
}
