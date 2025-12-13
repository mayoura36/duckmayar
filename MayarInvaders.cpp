//da el main bta3y
#include "raylib.h"
#include "game.hpp"
#include"theduck.hpp"
//#include "laser.hpp"
#include<string>
//std::string FormatWithLeadingZeros(int number, int width)
//{
//	std::string numberText = std::to_string(number);
//	int leadingZeros = 5 - numberText.length();
//	return numberText = std::string(leadingZeros, '0') + numberText;
//}
int main()
{
	Color grey = { 29,29,27,255 };
	Color pink = { 213,0,149,100 };
	int screenWidth = 1200;
	int screenHeight = 800;
	InitWindow(screenWidth, screenHeight, "C++ Duck Invaders");
	InitAudioDevice();
	Font font = LoadFontEx("Font/MonterratAlternates-Bold.otf", 64, 0, 0);
	Texture2D livesImage = LoadTexture("Graphics/pink_bow_lives.png");
	SetTargetFPS(60);
	Game game;
	Engduck engduck = Engduck(1, { 100,1000 });

	//Background
	Texture2D background = LoadTexture("Graphics/background_3.png");

	//Laser laser = Laser({ 100,100 }, -7);
	while (WindowShouldClose() == false)
	{
		UpdateMusicStream(game.music);
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
			std::string levelCount = "LEVEL " + std::to_string(game.level);
			DrawTextEx(font, levelCount.c_str(), { 980,745 }, 34, 2, pink);
		}
		else
		{
		DrawTextEx(font, "PRESS ENTER TO RESTART", { 930 - 230,680 }, 34, 2, pink);
			DrawTextEx(font, "GAME OVER", { 960,745 }, 34, 2, pink);
		}
		float x = 75.0;
		for (int i = 0; i < game.lives; i++)
		{
			DrawTextureV(livesImage, { x,745 }, WHITE);
			x += 75.0;
		}
		DrawTextEx(font, "SCORE", { 30,690 }, 34, 2, pink); //msh shayfaha
		//std::string scoreText = FormatWithLeadingZeros(game.score, 5);
		std::string scoreText = std::to_string(game.score);
		DrawTextEx(font, scoreText.c_str(), { 30 + 120,690 }, 34, 3, pink);
		DrawTextEx(font, "HIGH-SCORE", { 600 - 150,745 }, 34, 2, pink);
		//std::string highscoreText = FormatWithLeadingZeros(game.highscore, 5);
		std::string highscoreText = std::to_string(game.highscore);
		DrawTextEx(font, highscoreText.c_str(), { 600 - 150 + 220,745 }, 34, 3, pink);
		game.Draw();
		//DrawTextEx(font, "PRESS ENTER TO RESTART", { 600 - 230,350 }, 34, 2, pink);
		//engduck.Draw();
		//laser.Draw();
		EndDrawing();
	}
	UnloadTexture(background);
	CloseWindow();
	CloseAudioDevice();
}
