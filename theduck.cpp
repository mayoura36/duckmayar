#include"theduck.hpp"
Engduck::Engduck(int type, Vector2 position)
{
	this->type = type;
	this->position = position;
	switch (type)
	{
	case 1:
		//image = LoadTexture("Graphics/yellow_duck.png");
		Image temp_imagem = LoadImage("Graphics/yellow_duck.png");
		const float scalem = 0.2;
		int newWidthm = temp_imagem.width * scalem;
		int newHeightm = temp_imagem.height * scalem;
		ImageResize(&temp_imagem, newWidthm, newHeightm);
		image = LoadTextureFromImage(temp_imagem);
		UnloadImage(temp_imagem);
		break;
	case 2:
		image = LoadTexture("Graphics/beige_duck.png");
		break;
	case 3:
		image = LoadTexture("Graphics/pink_duck.png");
		break;
	default:
		image = LoadTexture("Graphics/yellow_duck.png");
		break;
	}
}
void Engduck::Draw() {
	DrawTextureV(image, position, WHITE);
}
int Engduck::GetType() {
	return type;
}