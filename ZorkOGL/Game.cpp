#include "Game.h"
#include "GUI.h"
#include "Player.h"
#include "InputListener.h"
#include <SDL.h>

Game::Game(void)
{	
	isRunning = true;
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
	InputListener input;
	GUI gui(1280, 720);
	gui.setupWindow();
	gui.setupRenderer();
	Player player("JAMES", 1, 2, 5, 6);
	while(isRunning)
	{		
		// Listen
		if(!input.listen())
		{
			isRunning = false;
		}
		
		// Render
		// TODO: Check if any changes have been made before rendering (improved performance)
				
		player.setHealth(player.getHealth() - 1);
		gui.drawPlayer(player);
		gui.drawOptions();
		gui.drawOpponent();
		gui.drawGameScreen();		
		
		gui.flush();		
		Sleep(1000);
	}
	
}