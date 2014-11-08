#pragma once
#include "Game.h"

class InputListener
{
public:
	// Constructor takes a pointer to a game
	InputListener(Game* game);
	
	// Listens for exit events, keyboard events and mouse events
	bool listen();

private:
	// Pointer to the game
	Game* game;
	
	// Listens for keyboard input
	bool getKeyboardInput(const SDL_Event event);
	
	// Listens for mouse input
	void getMouseInput(const SDL_Event event);
};

