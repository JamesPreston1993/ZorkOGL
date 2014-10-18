#include "Game.h"
#include "GUI.h"
#include "GameObject.h"
#include "InputListener.h"
#include <SDL.h>

Game::Game(void)
{	
	isRunning = true;
	stateChanged = true;
	player = new Player("ARAGORN", 9, 2, 5, 6);
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
	// Delete enemy if they exist - doesn't work
	SDL_Quit();
}

void Game::run()
{	
	// Create an input listener
	InputListener* input = new InputListener(this);
	
	// Create the GUI specifying the screen width and height
	GUI gui(1280, 720);	

	// Start the game loop
	while(isRunning)
	{		
		// Listen for events
		if(!input->listen())
		{
			isRunning = false;
		}		

		// Render if the state has changed - avoids unnecessary rendering
		if(stateChanged)
		{
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
