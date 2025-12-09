#pragma once
#include"raylib.h"
class Engduck {
public:
	Engduck(int type, Vector2 position);
	void Update();
	void Draw();
	int GetType();
	static Texture2D duckImages[3];
	int type;
	Vector2 position;
private:
};