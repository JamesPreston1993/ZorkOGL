#include "InputListener.h"
#include "Game.h"
#include <SDL.h>

InputListener::InputListener(Game* game)
{
	this->game = game;
}


InputListener::~InputListener()
{
	
}

bool InputListener::listen()
{
	SDL_Event event;
	
	SDL_WaitEvent(&event);
	
	// If the window is closed, end the game loop
	if(event.type == SDL_QUIT)
	{
		return false;
	}		

	// Test keyboard input
	getKeyboardInput(event);

	// Test mouse input
	getMouseInput(event);

	// Delay - Improves CPU performance
	SDL_Delay(10);
		
	return true;
}

void InputListener::getKeyboardInput(SDL_Event event)
{
	if(event.type == SDL_KEYDOWN)
	{
		// DEBUG: Press space takes away health from enemy
		if(event.key.keysym.sym == SDLK_SPACE)
		{
			if(game->getEnemySelected())
			{
				game->getOpponent()->setHealth(game->getOpponent()->getHealth() - game->getPlayer()->getStrength());
				game->setStateChanged(true);
				if(game->getOpponent()->getHealth() == 0)
				{
					game->setEnemySelected(false);					
					delete game->getOpponent();
				}
			}
		}
		// DEBUG: Press escape to close the game
		if(event.key.keysym.sym == SDLK_ESCAPE)
		{
			SDL_Quit();
		}
	}
}

void InputListener::getMouseInput(SDL_Event event)
{
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{

	}
	if(event.type == SDL_MOUSEBUTTONUP)
	{

	}
}