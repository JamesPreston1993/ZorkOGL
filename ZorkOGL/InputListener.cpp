#include "InputListener.h"
#include "Game.h"
#include <SDL.h>
//#include "SDL_opengl.h"

InputListener::InputListener(Game game)
{
	this->game = &game;
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
			// DEBUG: Press space takes away health
			game->getPlayer()->setHealth(game->getPlayer()->getHealth() - 10);
			game->setStateChanged(true);
		}
	}		
	// Test mouse input
		
	// Delay
	SDL_Delay(10);
		
	return true;
}