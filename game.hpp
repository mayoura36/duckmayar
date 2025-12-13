#pragma once
#include "watergun.hpp"
#include "theduck.hpp"
#include "laser.hpp"


#define duckRows 4
#define duckColumns 10

class Game {
public:
	Game();
	~Game();
	void Draw();
	void Update();
	void HandleInput();
	bool run;
	int lives;
	int level;
	int score;
	int counter;
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
	void NextLevel();
	void Reset();
	void InitGame();
	void checkForHighscore();
	void saveHighscoreToFile(int highscore);
	int loadHighscoreFromFile();
	WaterGun watergun;
	std::vector<Engduck>engducks;
	int engducksDirection;
	std::vector<Laser>engduckLaser;
	constexpr static float engduckLaserShootInterval = 0.35;
	float lastFireTime;
	Sound explosionSound;
	Sound egg;
};
