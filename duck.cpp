#include "duck.hpp"

Theduck::Theduck()
{
	//image = LoadTexture("Graphics/water_gun_closed.png");
	Image temp_image = LoadImage("Graphics/water_gun_closed.png");
	const float scale = 0.18;
	int newWidth = temp_image.width * scale;
	int newHeight = temp_image.height * scale;
	ImageResize(&temp_image, newWidth, newHeight);
	image = LoadTextureFromImage(temp_image);
	UnloadImage(temp_image);
	position.x = (GetScreenWidth() - image.width) / 2;
	position.y = GetScreenHeight() - image.height - 100;
	lastFireTime = 0.0;
	laserSound = LoadSound("soundeffects/water_sound.mp3");
}
Theduck::~Theduck()
{
	UnloadTexture(image);
	UnloadSound(laserSound);
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
	if (position.x > GetScreenWidth() - image.width)
	{
		position.x = GetScreenWidth() - image.width;
	}
}
void Theduck::FireLaser() {
	if (GetTime() - lastFireTime >= 0.35)
	{
		lasers.push_back(Laser({ position.x + image.width / 2 - 2,position.y }, -6));
		lastFireTime = GetTime();
		PlaySound(laserSound);
	}
}
Rectangle Theduck::getRect() {
	return { position.x,position.y,float(image.width),float(image.height) };
}
void Theduck::Reset()
{
	position.x = (GetScreenWidth() - image.width) / 2.0f;
	position.y = GetScreenHeight() - image.height - 100;
	lasers.clear();
}