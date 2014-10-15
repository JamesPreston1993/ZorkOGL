#pragma once
#include "Game.h"
class InputListener
{
public:
	InputListener(Game* game);
	~InputListener();
	bool listen();
private:
	Game* game;
	bool getKeyboardInput(SDL_Event event);
	void getMouseInput(SDL_Event event);
};

