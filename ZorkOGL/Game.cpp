#include "Game.h"
#include "GUI.h"
#include "Player.h"
#include "Character.h"
#include "InputListener.h"
#include <SDL.h>

Player* player;
Character* enemy;
bool stateChanged;

Game::Game(void)
{	
	isRunning = true;
	stateChanged = true;
	player = new Player("ARAGORN", 1, 2, 5, 6);
	enemy = new Character("BANDIT",3,2,1,4);
}

Game::~Game(void)
{

}

int main(int argc, char *args[])
{	
	Game game;
	game.run();
	SDL_Quit();
	return 0;
}

void Game::run()
{	
	InputListener* input = new InputListener(*this);
	GUI gui(1280, 720);
	bool enemyAlive = false;	
	while(isRunning)
	{		
		// Listen
		if(!input->listen())
		{
			isRunning = false;
		}
		
		// Render
		// TODO: Check if any changes have been made before rendering (improved performance)
			
		
		if(stateChanged)
		{
			/* 
				***** WARNING ****
				*  Memory leak   *
				******************
			*/
			stateChanged = false;			
			gui.drawPlayer(player);
			gui.drawOptions();
			if(enemy != NULL)
				gui.drawOpponent(enemy);
			else
				gui.drawOpponent();
			gui.drawGameScreen();		
		
			gui.flush();
		}		
	}	
}

void Game::setStateChanged(bool state)
{
	if(state != stateChanged)
	{
		stateChanged = state;
	}
}

Player* Game::getPlayer()
{
	return player;
}

Character* Game::getOpponent()
{
	return enemy;
}