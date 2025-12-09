#pragma once
#include "duck.hpp"
#include"theduck.hpp"
class Game {
public:
	Game();
	~Game();
	void Draw();
	void Update();
	void HandleInput();
private:
	void DeleteInactiveLasers();
	std::vector<Engduck>CreateEngducks();
	Theduck duck;
	std::vector<Engduck>engducks;
};
