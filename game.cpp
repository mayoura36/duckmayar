#include "game.hpp"
#include<iostream>
#include<fstream>
Game::Game()
{
	engducks = CreateEngducks();
	engducksDirection = 1;
	lastFireTime = 0.0;
	lives = 3;
	run = true;
	music = LoadMusicStream("soundeffects/backmusic.mp3");//hena el music bta3ty
	PlayMusicStream(music);
	InitGame();
}
Game::~Game()
{
	UnloadMusicStream(music);
}
void Game::Update()
{
	if (run)
	{
		double currentTime = GetTime();
		for (auto& laser : duck.lasers)
		{
			laser.Update();
		}
		MoveEngducks();
		EngduckShootLaser();
		for (auto& laser : engduckLaser)
		{
			laser.Update();
		}
		DeleteInactiveLasers();
		CheckForCollisions();
	}
	else
	{
		if (IsKeyDown(KEY_ENTER))
		{
			Reset();
			InitGame();
		}
	}
}
void Game::Draw()
{
	duck.Draw();
	for (auto& laser : duck.lasers)
	{
		laser.Draw();

	}
	for (auto& engduck : engducks)
	{
		engduck.Draw();
	}
	for (auto& laser : engduckLaser)
	{
		laser.DrawEgg();
	}
}
void Game::HandleInput()
{
	if (run)
	{
		if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
		{
			duck.MoveLeft();
		}
		if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
		{
			duck.MoveRight();
		}
		if (IsKeyPressed(KEY_SPACE))
		{
			duck.FireLaser();
		}
	}
}
void Game::DeleteInactiveLasers()
{
	for (auto it = duck.lasers.begin(); it != duck.lasers.end();) {
		if (!it->active)
		{
			it = duck.lasers.erase(it);
		}
		else
		{
			++it;
		}
	}
	for (auto it = engduckLaser.begin(); it != engduckLaser.end();) {
		if (!it->active)
		{
			it = engduckLaser.erase(it);
		}
		else
		{
			++it;
		}
	}
}
std::vector<Engduck> Game::CreateEngducks()
{
	std::vector<Engduck>engducks;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 10; col++)
		{
			int engduckType;
			if (row == 0)
			{
				engduckType = 3;
			}
			else if (row == 1)
			{
				engduckType = 2;
			}
			else if (row==2)
			{
				engduckType = 2;
			}
			else
			{
				engduckType = 1;
			}
			float x = 10 + col * 110;
			float y = 15 + row * 90;
			engducks.push_back(Engduck(engduckType, { x,y }));
		}
	}
	return engducks;
}
void Game::MoveEngducks()
{
	for (auto& engduck : engducks)
	{
		if (engduck.position.x + engduck.duckImages[engduck.type - 1].width > GetScreenWidth() - 20)
		{
			engducksDirection = -1;
			MoveDownEngducks(4);
		}
		if (engduck.position.x < 0)
		{
			engducksDirection = 1;
			MoveDownEngducks(4);
		}
		engduck.Update(engducksDirection);
	}
}
void Game::MoveDownEngducks(int distance)
{
	for (auto& engduck : engducks)
	{
		engduck.position.y += distance;
	}
}
void Game::EngduckShootLaser()
{
	double currentTime = GetTime();
	if (currentTime - lastFireTime >= engduckLaserShootInterval && !engducks.empty())
	{
		int randomIndex = GetRandomValue(0, engducks.size() - 1);
		Engduck& engduck = engducks[randomIndex];
		engduckLaser.push_back(Laser(
			{ engduck.position.x + engduck.duckImages[engduck.type - 1].width / 2,engduck.position.y + engduck.duckImages[engduck.type - 1].height }, 6, "Graphics/egg.png"));
		lastFireTime = GetTime();
	}
}
void Game::CheckForCollisions()
{
	//watergun lasers
	for (auto& laser : duck.lasers)
	{
		auto it = engducks.begin();
		while (it != engducks.end())
		{
			if (CheckCollisionRecs(it->getRect(), laser.getRect()))
			{
				if (it->type == 1)
				{
					score += 100;
				}
				else if (it->type == 2)
				{
					score += 200;
				}
				else if (it->type == 3)
				{
					score += 300;
				}
				checkForHighscore();
				it = engducks.erase(it);//true collision
				laser.active = false;//laser inactive
			}
			else
			{
				//no collision
				++it;
			}
		}
	}
	for (auto& laser : engduckLaser)
	{
		if (CheckCollisionRecs(laser.getRectEgg(), duck.getRect()))
		{
			laser.active = false;
			lives--;
			if (lives == 0)
			{
				GameOver();
			}
		}
	}
	for (auto& engduck : engducks)
	{
		if (CheckCollisionRecs(engduck.getRect(), duck.getRect()))
		{
			GameOver();
		}
	}
}
void Game::GameOver()
{
	run = false;
}
void Game::InitGame()
{
	engducks = CreateEngducks();
	engducksDirection = 1;
	lastFireTime = 0.0;
	lives = 3;
	score = 0;
	highscore = loadHighscoreFromFile();
	run = true;
}
void Game::checkForHighscore()
{
	if (score > highscore)
	{
		highscore = score;
		saveHighscoreToFile(highscore);
	}
}
void Game::saveHighscoreToFile(int highscore)
{
	std::ofstream highscoreFile("highscore.txt");
	if (highscoreFile.is_open())
	{
		highscoreFile << highscore;
		highscoreFile.close();
	}
	else
	{
		std::cerr << "Failed to save highscore to file" << std::endl;
	}
}
int Game::loadHighscoreFromFile()
{
	int loadedHighscore = 0;
	std::ifstream highscoreFile("highscore.txt");
	if (highscoreFile.is_open())
	{
		highscoreFile >> loadedHighscore;
		highscore >> loadedHighscore;
		highscoreFile.close();
	}
	else
	{
		std::cerr << "Failed to load highscore from file." << std::endl;
	}
	return loadedHighscore;
}
void Game::Reset()
{
	duck.Reset();
	engducks.clear();
	engduckLaser.clear();

}