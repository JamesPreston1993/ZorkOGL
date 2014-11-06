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
	bool getKeyboardInput(const SDL_Event event);
	void getMouseInput(const SDL_Event event);
};

