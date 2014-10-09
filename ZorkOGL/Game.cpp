#include "Game.h"
#include "GUI.h"
#include "GameObject.h"
#include "InputListener.h"
#include <SDL.h>

Game::Game(void)
{	
	isRunning = true;
	stateChanged = true;
	enemySelected = true;
	player = new Player("ARAGORN", 9, 2, 5, 6);
	enemy = new Enemy("BANDIT", GameObject::BANDIT);
}

Game::~Game(void)
{		
	delete player;
	// Delete enemy if they exist - doesn't work	
	SDL_Quit();
}

void Game::run()
{	
	InputListener* input = new InputListener(this);
	GUI gui(1366, 768);	
	while(isRunning)
	{		
		// Listen for events
		if(!input->listen())
		{
			isRunning = false;
		}
		
		// Render
		if(stateChanged)
		{
			stateChanged = false;			
			gui.drawCharacter(player);
			gui.drawInventory(player);
			if(enemySelected)
				gui.drawCharacter(enemy);
			else
				gui.drawCharacter();
			gui.drawGameScreen();
		
			gui.flush();
		}		
	}
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