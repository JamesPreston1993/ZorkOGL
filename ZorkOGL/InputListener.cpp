#include "InputListener.h"

// Constructor takes a pointer to a game
InputListener::InputListener(Game* game)
{
	this->game = game;
}

// Listens for exit events, keyboard events and mouse events
bool InputListener::listen()
{
	// Create an event
	SDL_Event event;
	
	// Wait until the event to trigger something
	SDL_WaitEvent(&event);
	
	// If the window is closed, end the game loop
	if(event.type == SDL_QUIT)
	{
		return false;
	}		

	// Test keyboard input
	if(!getKeyboardInput(event))
	{
		// If the ESC key is pressed, end the game loop
		return false;
	}

	// Test mouse input
	getMouseInput(event);

	// Delay - Improves CPU performance
	SDL_Delay(10);
		
	return true;
}

bool InputListener::getKeyboardInput (const SDL_Event event)
{
	// Check if key on keyboard is pressed down
	if(event.type == SDL_KEYDOWN)
	{
		// Press escape to close the game
		if(event.key.keysym.sym == SDLK_ESCAPE)
		{
			return false;
		}
		// Press Z to go to previous inventory item
		if(event.key.keysym.sym == SDLK_z)
		{
			game->getPlayer()->setCurrentItemIndex(-1);
			game->setStateChanged(true);
		}
		// Press X to go to next inventory item
		if(event.key.keysym.sym == SDLK_x)
		{
			game->getPlayer()->setCurrentItemIndex(1);
			game->setStateChanged(true);
		}
	}
	return true;
}

void InputListener::getMouseInput(const SDL_Event event)
{
	// Check if the mouse button is pressed down
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{
		// Get the X and Y coordinates of the mouse on screen
		int mouseX = event.button.x;
		int mouseY = event.button.y;
		
		// Check if the player is attacking an enemy or picking up an item
		if(game->getEnemySelected())
		{
			// Check if the object being clicked is a enemy
			if(game->getOpponent()->mouseInside(mouseX, mouseY))
			{
				// Enemy attempts to dodge either successfully or unsuccesfully
				game->getOpponent()->dodge();
				
				// Decrement the enemy's health by the player's strength
				game->getOpponent()->setHealth(game->getOpponent()->getHealth() - game->getPlayer()->getStrength());
				
				// If the enemy's health is zero remove him from the scene
				if(game->getOpponent()->getHealth() == 0)
				{
					game->setEnemySelected(false);
					game->getCurrentScene()->removeEnemy(game->getCurrentScene()->getEnemy());					
				}
				
				// Set the state to changed so the scene is rendered
				game->setStateChanged(true);
			}
		}
		else
		{
			// Go through all items in the scene until the item being clicked is found
			for(int i = 0; i < game->getCurrentScene()->getItems().size(); i++)
			{
				if(game->getCurrentScene()->getItems().at(i).mouseInside(mouseX, mouseY))
				{
					// Add the item to the player's inventory and remove it from the scene
					game->getPlayer()->addToInventory(game->getCurrentScene()->getItems().at(i));
					game->getCurrentScene()->removeItem(game->getCurrentScene()->getItems().at(i));
					
					// Set the state to changed so the scene is rendered
					game->setStateChanged(true);
					
					// Break from the loop once the item has been found
					break;					
				}
			}
		}
	}
}