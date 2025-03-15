#include <iostream>
#include <GLFW/glfw3.h>

#include "raylib.h"

#include "resource_dir.h"



#define WindowWidth (float) 1280
#define WindowHeight (float) 720

#include "game/Game.h"



int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	
	InitWindow(WindowWidth, WindowHeight, "Game");
	
	SearchAndSetResourceDir("resources");

	Game* game = new Game();
	
	SetTargetFPS(160);  
	// game loop
	
	while (!WindowShouldClose())
	{
		game->update();
		
		
		BeginDrawing();
		
		game->render();
		
		EndDrawing();
	}
	
	
	CloseWindow();
	return 0;
}
