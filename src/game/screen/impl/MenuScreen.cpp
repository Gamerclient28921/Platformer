#include "MenuScreen.h"

#include "game/Game.h"

void onStartButton()
{
    game->currentScreen = new GameScreen(game->getFont());
}

void MenuScreen::init()
{
    Button StartButton = Button("Start Game", 20, 20, 16,&onStartButton, this);

    this->buttons.push_back(StartButton);
}



void MenuScreen::render(const int& ticks)
{
    for (auto button : this->buttons)
    {
        button.render();
    }
}

void MenuScreen::update(const int& ticks)
{
    for (auto button : this->buttons)
    {
        button.update();
    }
}
