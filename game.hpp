#pragma once
#include "duck.hpp"
#include "theduck.hpp"
#include "laser.hpp"

class Game {
public:
	Game();
	~Game();
	void Draw();
	void Update();
	void HandleInput();
	bool run;
private:
	void DeleteInactiveLasers();
	std::vector<Engduck>CreateEngducks();
	void MoveEngducks();
	void MoveDownEngducks(int distance);
	void EngduckShootLaser();
	void CheckForCollisions();
	void GameOver();
	void Reset();
	void InitGame();
	Theduck duck;
	std::vector<Engduck>engducks;
	int engducksDirection;
	std::vector<Laser>engduckLaser;
	constexpr static float engduckLaserShootInterval = 0.35;
	float lastFireTime;
	int lives;
};
