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
	if(!getKeyboardInput(event))
	{
		return false;
	}

	// Test mouse input
	getMouseInput(event);

	// Delay - Improves CPU performance
	SDL_Delay(10);
		
	return true;
}

bool InputListener::getKeyboardInput (SDL_Event event)
{
	if(event.type == SDL_KEYDOWN)
	{
		// Press escape to close the game
		if(event.key.keysym.sym == SDLK_ESCAPE)
		{
			return false;
		}
	}
	return true;
}

void InputListener::getMouseInput(SDL_Event event)
{
	
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{
		int mouseX = event.button.x;
		int mouseY = event.button.y;
		if(game->getEnemySelected())
		{
			if(game->getOpponent()->mouseInside(mouseX, mouseY))
			{
				game->getOpponent()->setHealth(game->getOpponent()->getHealth() - game->getPlayer()->getStrength());
				if(game->getOpponent()->getHealth() == 0)
				{
					// DEBUG 
					game->setEnemySelected(false);
					game->getCurrentScene()->removeEnemy(game->getCurrentScene()->getEnemy());
					//delete game->getOpponent();
					game->setCurrentScene(Scene::MAIN_HALL);
				}
				game->setStateChanged(true);
			}
		}
		else
		{
			for(int i = 0; i < game->getCurrentScene()->getItems().size(); i++)
			{
				if(game->getCurrentScene()->getItems().at(i).mouseInside(mouseX, mouseY))
				{
					game->getPlayer()->addToInventory(game->getCurrentScene()->getItems().at(i));
					game->getCurrentScene()->removeItem(game->getCurrentScene()->getItems().at(i));
					game->setStateChanged(true);
					break;
										
				}
			}
		}
	}
	if(event.type == SDL_MOUSEBUTTONUP)
	{

	}
}