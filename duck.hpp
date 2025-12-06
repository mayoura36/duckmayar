#pragma once
#include <raylib.h> 
class Theduck
{
public: 
    Theduck();
    ~Theduck();
     void Draw();
     void MoveLeft();
     void MoveRight();
     void FireLaser();
private: 
    Texture2D image;
	Vector2 position;
};
