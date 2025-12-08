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