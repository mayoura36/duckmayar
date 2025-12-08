// MayarInvaders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//da el main bta3y
#include "raylib.h"
#include "game.hpp"
#include"theduck.hpp"
//#include "laser.hpp"

int main()
{
	Color grey{ 29,29,27,255 };
	int windowwidth = 750;
	int windowheight = 700;
	InitWindow(windowwidth, windowheight, "C++ Duck Invaders");
	SetTargetFPS(60);
	Game game;
	Duck ;
	//Laser laser = Laser({ 100,100 }, -7);
	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		game.Update();
		//laser.Update();
		BeginDrawing();
		ClearBackground(grey);
		game.Draw();
		//laser.Draw();
		EndDrawing();
	}
	CloseWindow();
}
