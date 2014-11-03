#include "Game.h"
#include "GUI.h"
#include "GameObject.h"
#include "InputListener.h"
#include <SDL.h>

Game::Game(void)
{	
	isRunning = true;
	stateChanged = true;
	player = new Player("ARAGORN", 9, 2, 5, 7);
	currentScene = new Scene(Scene::GATES);

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

Game::~Game(void)
{		
	delete player;
	delete currentScene;
	SDL_Quit();
}

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
		// Listen for events
		if(!input->listen())
		{
			isRunning = false;
		}		

		if(enemySelected)
		{
			if(enemy->canAttack(attackTimer))
			{
				if(enemy->attack(player))
				{
					stateChanged = true;
					attackTimer = 0;
					if(player->getHealth() == 0)
					{
						isRunning = false;
						SDL_ShowSimpleMessageBox(NULL,"Game Over", "You died!", NULL);
					}
				}
			}
			else
			{
				attackTimer++;
			}
		}

		// Render if the state has changed - avoids unnecessary rendering
		if(stateChanged)
		{
			if(currentScene->isComplete())
				setCurrentScene(currentScene->getNextScene());
			stateChanged = false;			
			gui.drawCharacter(player);
			gui.drawInventory(player);
			
			// If the player has selected an opponent, their stats will be displayed
			if(enemySelected)
				gui.drawCharacter(enemy);
			else
				gui.drawCharacter();
			
			gui.drawGameScreen(currentScene);
		
			// Flush to screen
			gui.flush();
			gui.clear();
		}		
	}
	// Delete the input listener
	delete input;
}

void Game::setStateChanged(bool state)
{
	if(state != stateChanged)
	{
		stateChanged = state;
	}
}

void Game::setEnemySelected(bool selected)
{
	if(selected != enemySelected)
	{
		enemySelected = selected;
	}
}
bool Game::getEnemySelected()
{
	return enemySelected;
}

Player* Game::getPlayer()
{
	return player;
}

Enemy* Game::getOpponent()
{
	return enemy;
}

void Game::setCurrentScene(Scene::SceneID newScene)
{
	if(newScene != currentScene->getID())
	{
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

Scene* Game::getCurrentScene()
{
	return currentScene;
}