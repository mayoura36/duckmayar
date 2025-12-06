#pragma once
#include "duck.hpp"
class Game {
public:
	Game();
	~Game();
	void Draw();
	void Update();
	void HandleInput();
private:
	Theduck duck;
};
