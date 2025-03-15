#include <iostream>
#include <GLFW/glfw3.h>

#include "raylib.h"

#include "resource_dir.h"

#include "engine/assets/ResourceLocation.h"
#include "engine/render/Screen.h"

#define WindowWidth (float) 1280
#define WindowHeight (float) 720

#include "game/entity/impl/Player.h"
#include "game/screen/GameScreen.h"



int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	
	InitWindow(WindowWidth, WindowHeight, "Game");
	
	SearchAndSetResourceDir("resources");
	
	Font roboto = LoadFont("../res/Font/Roboto.ttf");
	ResourceLocation* playerSprite = new ResourceLocation("../res/PlayerSprite.png");
	Player* player = new Player(0, 0, playerSprite);
	
	Screen* currentScreen = new GameScreen(roboto);
	
	SetTargetFPS(160);  
	// game loop
	int ticks = 0;
	while (!WindowShouldClose())
	{
		
		if (IsKeyDown(KEY_F3))
			currentScreen->renderDebugMenu = !currentScreen->renderDebugMenu;
		
		
		
		
		// drawing
		BeginDrawing();
		
		if (currentScreen->type == ScreenType::GameScreen)
		{
			GameScreen* game_screen = static_cast<GameScreen*>(currentScreen);

			
			
			game_screen->render(*player, ticks);

			ClearBackground(BLUE);
			player->render();
			
			DrawRectangle(200, 200, 200, 20, GREEN);
		}
		
		player->update(ticks);
		
		
		EndDrawing();
		ticks++;
	}
	
	
	CloseWindow();
	return 0;
}
