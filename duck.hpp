#pragma once
#include <raylib.h> 
#include"laser.hpp"
#include<vector>
class Theduck
{
public: 
    Theduck();
    ~Theduck();
     void Draw();
     void MoveLeft();
     void MoveRight();
     void FireLaser();
     Rectangle getRect();
     std::vector<Laser>lasers;
private: 
    Texture2D image;
	Vector2 position;
    double lastFireTime;
};
