// MayarInvaders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//da el main bta3y
#include "raylib.h"
#include "game.hpp"
#include"theduck.hpp"
//#include "laser.hpp"
#include<string>
std::string FormatWithLeadingZeros(int number, int width)
{
	std::string numberText = std::to_string(number);
	int leadingZeros = 5 - numberText.length();
	return numberText = std::string(leadingZeros, '0') + numberText;
}
int main()
{
	Color grey = { 29,29,27,255 };
	Color pink = { 213,0,149,100 };
	int offset = 50;
	int windowwidth = 1150;
	int windowheight = 700;
	InitWindow(windowwidth + offset, windowheight + 2 * offset, "C++ Duck Invaders");
	Font font = LoadFontEx("Font/MonterratAlternates-Bold.otf", 64, 0, 0);
	Texture2D duckImage = LoadTexture("Graphics/pink_bow_lives.png");
	SetTargetFPS(60);
	Game game;
	Engduck engduck = Engduck(1, { 100,1000 });

	//Background
	Texture2D background = LoadTexture("Graphics/background.png");

	//Laser laser = Laser({ 100,100 }, -7);
	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		game.Update();
		//laser.Update();
		BeginDrawing();
		ClearBackground(grey);
		DrawTexture(background, 0, 0, WHITE);
		DrawRectangleRoundedLinesEx({ 10,10,1180,780 }, 0.18f, 20, 3, pink); //gdeda
		DrawLineEx({ 15,730 }, { 1180,730 }, 3, pink); //gdeda
		if (game.run)
		{
			DrawTextEx(font, "LEVEL 01", { 965,740 }, 34, 2, pink);
		}
		else
		{
			DrawTextEx(font, "GAME OVER", { 965,740 }, 34, 2, pink);
		}
		float x = 75.0;
		for (int i = 0; i < game.lives; i++)
		{
			DrawTextureV(duckImage, { x,745 }, WHITE);
			x += 75.0;
		}
		DrawTextEx(font, "SCORE", { 50,15 }, 34, 2, pink);///msh shayfaha
		std::string scoreText = FormatWithLeadingZeros(game.score,5);
		DrawTextEx(font, scoreText.c_str(), { 50,40 }, 34, 3, pink);
		DrawTextEx(font, "HIGH-SCORE", { 570,15 }, 34, 2, pink);
		std::string highscoreText = FormatWithLeadingZeros(game.highscore, 5);
		DrawTextEx(font, highscoreText.c_str(), { 1000,40 }, 34, 3, pink);
		game.Draw();
		//engduck.Draw();
		//laser.Draw();
		EndDrawing();
	}
	UnloadTexture(background);
	CloseWindow();
}
