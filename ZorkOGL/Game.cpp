#include "Game.h"
#include "GUI.h"
#include "InputListener.h"

// Constructor initialises attributes of the class
Game::Game()
{	
	// Initialise the attrbutes of the class
	isRunning = true;
	stateChanged = true;
	player = new Player("ARAGORN", 9, 2, 5, 7);
	currentScene = new Scene(Scene::START);

	// If the scene has an enemy, set the current enemy to that scene's main enemy
	// Otherwise, set to NULL
	if(currentScene->hasEnemies())
	{
		enemy = currentScene->getEnemy();
		enemySelected = true;
	}
	else
	{
		enemy = NULL;
		enemySelected = false;
	}	
}

// Deletes all pointers in the class
Game::~Game()
{		
	delete player;
	delete currentScene;
	SDL_Quit();
}

// Run method containing th game loop that handles Logic, Events and Drawing
void Game::run()
{	
	// Create an input listener
	InputListener* input = new InputListener(this);
	
	// Create the GUI specifying the screen width and height
	GUI gui(1280, 720);	

	// Attack tiimer for enemy
	int attackTimer = 0;

	// Start the game loop
	while(isRunning)
	{		
		/**********
		 * EVENTS *
		 **********/

		// Listen for events - returns false if an exit event is received
		if(!input->listen())
		{
			isRunning = false;
		}

		/*********
		 * LOGIC *
		 *********/

		// Attack Logic
		if(enemySelected)
		{
			if(enemy->canAttack(attackTimer))
			{
				if(enemy->attack(player))
				{
					// If the enemy can attack set the stateChanged to true
					// and reset the attack timer
					stateChanged = true;
					attackTimer = 0;
					
					// If the player's health is 0 then the game is over
					if(player->getHealth() == 0)
					{
						setCurrentScene(Scene::GAMEOVER);
					}
				}
			}
			else
			{
				// If the enemy can't attack then increment the attack timer
				attackTimer++;
			}
		}

		// Only render if the state has changed - avoids unnecessary rendering
		if(stateChanged)
		{
			// If the player has killed all enemies and collected all items
			// go to the next scene
			if(currentScene->isComplete())
				setCurrentScene(currentScene->getNextScene());
			
			// Reset the state changed to false
			stateChanged = false;			
		
			/********
			 * DRAW *
			 ********/

			// Draw the player HUD panel
			gui.drawCharacter(player);

			// Draw the inventory HUD panel
			gui.drawInventory(player);
			
			// If the scene has an enemy, their stats will be displayed
			// Otherwise, an empty panel is displayed
			if(enemySelected)
				gui.drawCharacter(enemy);				
			else
				gui.drawCharacter();
			
			// Draw the main game screen
			gui.drawGameScreen(currentScene);
		
			// Flush to screen and clear the renderer
			gui.flush();
			gui.clear();
		}		
	}

	// Delete the input listener when the game loop ends
	delete input;
}

// Sets the stateChanged boolean that controls whether the GUI is updated
void Game::setStateChanged(const bool state)
{
	// Only update the stateChanged if the paramter does not have the same value
	// Increases speed and performance
	if(state != stateChanged)
	{
		stateChanged = state;
	}
}

// Sets the enemySelected boolean that states whether the scene has an enemy
void Game::setEnemySelected(const bool selected)
{
	// Only update the enemySelected if the paramter does not have the same value
	// Increases speed and performance
	if(selected != enemySelected)
	{
		enemySelected = selected;
	}
}

// Returns a boolean stating whether the scene has an enemy
bool Game::getEnemySelected()
{
	return enemySelected;
}

// Returns a pointer to the player
Player* Game::getPlayer()
{
	return player;
}

// Returns a pointer to the scene's enemy
Enemy* Game::getOpponent()
{
	return enemy;
}

// Sets the current scene of the game
void Game::setCurrentScene(const Scene::SceneID newScene)
{
	// Only chnage the current scene if the paramter does not match the ID of the currentScene
	// Increases speed and performance
	if(newScene != currentScene->getID())
	{
		// Delete the object that the scene pointer points to and create a new one
		delete currentScene;
		currentScene = new Scene(newScene);

		// If the scene has an enemy, set the current enemy to that scene's main enemy
		// Otherwise, set to NULL
		if(currentScene->hasEnemies())
		{
			enemy = currentScene->getEnemy();
			enemySelected = true;
		}
		else
		{
			enemy = NULL;
			enemySelected = false;
		}
	}
}

// Returns a pointer to the current scene
Scene* Game::getCurrentScene()
{
	return currentScene;
}