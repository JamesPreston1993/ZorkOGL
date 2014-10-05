#include "Game.h"
#include <SDL.h>
#include <vld.h>

int main(int argc, char *args[])
{	
	Game* game = new Game();
	game->run();	
	delete game;
	return 0;
}