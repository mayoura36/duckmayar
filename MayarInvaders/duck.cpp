#include "duck.hpp"

Theduck::Theduck()
{
	//image = LoadTexture("Graphics/water_gun_closed.png");
	Image temp_image = LoadImage("Graphics/water_gun_closed.png");
	const float scale = 0.2;
	int newWidth = temp_image.width * scale;
	int newHeight = temp_image.height * scale;
	ImageResize(&temp_image, newWidth, newHeight);
	image = LoadTextureFromImage(temp_image);
	UnloadImage(temp_image);
	position.x = (GetScreenWidth() - image.width)/2;
	position.y = GetScreenHeight() - image.height;
}
Theduck::~Theduck()
{
	UnloadTexture(image);
}
void Theduck::Draw()
{
	DrawTextureV(image, position, WHITE);
}
void Theduck::MoveLeft() {
	position.x -= 10;
	if (position.x < 0)
	{
		position.x = 0;
	}
}
void Theduck::MoveRight()
{
	position.x += 10;
	if(position.x>GetScreenWidth()-image.width)
	{ 
		position.x = GetScreenWidth() - image.width;
	}
}