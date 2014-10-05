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
	if(event.type == SDL_KEYDOWN)
	{
		if(event.key.keysym.sym == SDLK_SPACE)
		{
			// DEBUG: Press space takes away health from enemy
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
		if(event.key.keysym.sym == SDLK_ESCAPE)
		{
			return false;
		}
	}		
	// Test mouse input
		
	// Delay
	
	SDL_Delay(10);
		
	return true;
}