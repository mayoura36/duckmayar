#include "game.hpp"
Game::Game()
{

}
Game::~Game()
{

}
void Game::Draw() {
	duck.Draw();
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
}