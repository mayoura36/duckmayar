#pragma once
#include"raylib.h"
class Duck {
public:
	Duck(int type, Vector2 position);
	void Update();
	void Draw();
	int GetType();
	int type;
	Vector2 position;

private:
};
