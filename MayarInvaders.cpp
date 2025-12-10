// MayarInvaders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//da el main bta3y
#include "raylib.h"
#include "game.hpp"
#include"theduck.hpp"
//#include "laser.hpp"

int main()
{
	Color grey={ 29,29,27,255 };
	Color pink = { 213,0,149,100 };
	int offset = 50;
	int windowwidth = 1200;
	int windowheight =  800;
	InitWindow(windowwidth+offset, windowheight + 2*offset, "C++ Duck Invaders");
	SetTargetFPS(60);
	Game game;
	Engduck engduck = Engduck(1, { 100,1000 });
	//Laser laser = Laser({ 100,100 }, -7);
	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		game.Update();
		//laser.Update();
		BeginDrawing();
		ClearBackground(grey);
		DrawRectangleRoundedLines({10,10,1230,900}, 0.18f , 20 , pink ); //gdeda
		DrawLineEx({ 15,730 }, { 775,730 }, 3, pink); //gdeda
		game.Draw();
		//engduck.Draw();
		//laser.Draw();
		EndDrawing();
	}
	CloseWindow();
}
