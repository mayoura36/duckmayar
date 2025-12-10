#include "game.hpp"
#include<iostream>

Game::Game()
{
	engducks = CreateEngducks();
	engducksDirection = 1;
	lastFireTime = 0.0;
}
Game::~Game()
{

}
void Game::Update()
{
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
		laser.Draw();
	}
}
void Game::HandleInput()
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
	for (int row = 0; row < 3; row++) {
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
			else
			{
				engduckType = 1;
			}
			float x = 15 + col * 120;
			float y = 10 + row * 140;
			engducks.push_back(Engduck(engduckType, { x,y }));
		}
	}
	return engducks;
}
void Game::MoveEngducks()
{
	for (auto& engduck : engducks)
	{
		if (engduck.position.x + engduck.duckImages[engduck.type - 1].width > GetScreenWidth())
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
	if (currentTime - lastFireTime >= engduckLaserShootInterval && !engducks.empty()) {
		int randomIndex = GetRandomValue(0, engducks.size() - 1);
		Engduck& engduck = engducks[randomIndex];
		engduckLaser.push_back(Laser({ engduck.position.x + engduck.duckImages[engduck.type - 1].width / 2,engduck.position.y + engduck.duckImages[engduck.type - 1].height }, 6));
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
				it = engducks.erase(it);//true collision
				laser.active = false;//laser inactive
			}
			else
			{
				++it;
			}
		}
	}
}