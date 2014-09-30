#include "InputListener.h"
#include <SDL.h>
//#include "SDL_opengl.h"

InputListener::InputListener()
{
	
}


InputListener::~InputListener()
{

}

bool InputListener::listen()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		// If the window is closed, end the game loop
		if(event.type == SDL_QUIT)
		{
			return false;
		}		

		// Test mouse input
		
	}
	return true;
}