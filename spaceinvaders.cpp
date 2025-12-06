#include "spaceinvaders.hpp"
//da bta3 spaceship spaceship.cpp
Spaceship::Spaceship()
{
	image = LoadTexture("Graphics/duck_helmet.png");
	position.x = 100;
	position.y = 100;
}
Spaceship::~Spaceship() {
	UnloadTexture(image);
}
void Spaceship::Draw() {
	DrawTextureV(image, position, WHITE);
}
