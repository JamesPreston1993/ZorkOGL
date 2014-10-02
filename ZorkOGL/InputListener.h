#pragma once
#include "Game.h"
class InputListener
{
public:
	InputListener(Game game);
	~InputListener();
	bool listen();
private:
	Game* game;
};

