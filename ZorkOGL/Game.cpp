#include "Game.h"
#include "GUI.h"
#include "Player.h"
#include "InputListener.h"
#include <SDL.h>

//GLint screenWidth = 1280;
//GLint screenHeight = 720;
//SDL_Window* window;

Game::Game(void)
{
	// Initialise SDl	  
	
	// Set up Window
	//setupWindow();
	//setupRenderer();
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

void Game::setupWindow()
{
	// Set up display
	//SDL_Init(SDL_INIT_VIDEO);
	//window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, 0);	
}
void Game::setupRenderer()
{
	/* Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, 0, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
        SDL_ShowSimpleMessageBox(0, "Renderer init error",
            SDL_GetError(), window);
    // Set render color to red ( background will be rendered in this color )
    //SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );

	SDL_Surface* image = SDL_LoadBMP("playerImg.bmp");
	if (image == NULL)
        SDL_ShowSimpleMessageBox(0, "Image init error", SDL_GetError(),
            window);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
	if (texture == NULL)
        SDL_ShowSimpleMessageBox(0, "Texture init error",
            SDL_GetError(), window);
	SDL_RenderCopy(renderer, texture, NULL, NULL);

    // Clear winow
    //SDL_RenderClear( renderer );
	
	// Flush
	SDL_RenderPresent(renderer);	
	*/
	// Shader model
	//glShadeModel(GL_SMOOTH);

	// Set up for 2D Rendering
	//glMatrixMode(GL_PROJECTION);

	// Save
	//glLoadIdentity();

	// Disable depth checking
	//glDisable(GL_DEPTH_TEST);
}

void Game::run()
{	
	InputListener input;
	GUI gui(1280, 720);
	gui.setupWindow();
	gui.setupRenderer();
	Player player("Oisín", 1, 2, 5, 6);
	while(isRunning)
	{
		// Listen
		if(!input.listen())
		{
			isRunning = false;
		}
		
		// Render
		// TODO: Check if any changes have been made before rendering (improved performance)

		gui.drawPlayer(player);
		gui.drawOptions();
		gui.drawOpponent();
		gui.drawGameScreen();		
		
		gui.flush();
	}
	
}