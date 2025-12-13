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
	int lives;
	int score;
	int highscore;
	Music music;
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
	void checkForHighscore();
	void saveHighscoreToFile(int highscore);
	int loadHighscoreFromFile();
	Theduck duck;
	std::vector<Engduck>engducks;
	int engducksDirection;
	std::vector<Laser>engduckLaser;
	constexpr static float engduckLaserShootInterval = 0.35;
	float lastFireTime;
	Sound explosionSound;
};
