#include "game.hpp"
#include<iostream>
Game::Game()
{

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
}
void Game::HandleInput() {
	if (IsKeyDown(KEY_LEFT))
	{
		duck.MoveLeft();
	}
    else if (IsKeyDown(KEY_RIGHT))
	{
		duck.MoveRight();
	}
	else if (IsKeyDown(KEY_SPACE))
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