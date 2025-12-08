#include"theduck.hpp"
Duck::Duck(int type, Vector2 position) {
	this->type = type;
	this->position = position;
	Image temp_image = LoadImage("Graphics/duck_helmet.png");
	const float scale = 0.2;
	int newWidth = temp_image.width * scale;
	int newHeight = temp_image.height * scale;
	ImageResize(&temp_image, newWidth, newHeight);
	image = LoadTextureFromImage(temp_image);
	UnloadImage(temp_image);
}
void Duck::Draw() {
	DrawTextureV(image, position, WHITE);
}
int Duck::GetType()
{
	return type;
}