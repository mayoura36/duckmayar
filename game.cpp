#include "game.hpp"
#include<iostream>
Game::Game()
{
	engducks = CreateEngducks();
}
Game::~Game()
{

}
void Game::Update() {
	for (auto& laser : duck.lasers)
	{
		laser.Update();
	}
	DeleteInactiveLasers();
}
void Game::Draw() {
	duck.Draw();
	for (auto& laser : duck.lasers)
	{
		laser.Draw();

	}
	for (auto& engduck : engducks) {
		engduck.Draw();
	}
}
void Game::HandleInput() {
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