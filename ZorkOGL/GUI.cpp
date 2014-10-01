#include "GUI.h"
#include <SDL.h>
#include "SDL_opengl.h"
#include <SDL_ttf.h>
#include <iostream>

using std::cerr;
using std::endl;

SDL_Window* window;
SDL_Renderer* renderer;

GUI::GUI(GLint width, GLint height)
{
	screenWidth = width;
	screenHeight = height;
	margin = 3;
}


GUI::~GUI(void)
{

}

void GUI::setupWindow()
{
	// Set up display
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	window = SDL_CreateWindow("ZorkOGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, 0);
}
void GUI::setupRenderer()
{
	// Initialise renderer
	renderer =  SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);	
    
	// Set render color to dark grey
    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255 );
		
	// Flush
	flush();
}
void GUI::flush()
{
	// Flush
	SDL_RenderPresent(renderer);
}

void GUI::clear()
{
	// Clear
	SDL_RenderClear(renderer);
}

void GUI::drawPlayer(Player player)
{
	int startX = margin;
	int startY = screenHeight - 220;
	int width = (screenWidth - (4 * margin)) / 3;
	int height = 220 - margin;
	
	// Draw the holder rectangle

	// Set render color to dark grey
    SDL_SetRenderDrawColor(renderer, 65, 65, 65, 255 );

	SDL_Rect* mainRect = new SDL_Rect();
	mainRect->x = startX;
	mainRect->y = startY;
	mainRect->w = width;
	mainRect->h = height;
	SDL_RenderFillRect(renderer, mainRect);

	// Set render color to medium grey
    SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255 );

	SDL_Rect* pictureRect = new SDL_Rect();
	pictureRect->x = startX + margin;
	pictureRect->y = startY + margin;
	pictureRect->w = width / 2 - margin;
	pictureRect->h = height - (2 * margin);
	SDL_RenderFillRect(renderer, pictureRect);

	drawStats(startX, startY, pictureRect->w, pictureRect->h, player);
}

/* Need to implement Enemy class
void GUI::drawOpponent(Enemy enemy)
{
	glPushMatrix();
	
	glOrtho(0,1280,720,0,-1,1);

	glColor3f(0.25, 0.25, 0.25);
	
	glBegin(GL_QUADS);
		glVertex2f(850, 475);
		glVertex2f(1275, 475);
		glVertex2f(1275, 715);
		glVertex2f(850, 715);
	glEnd();

	glPopMatrix();
}
*/

void GUI::drawOpponent()
{
	int width = (screenWidth - (4 * margin)) / 3;
	int height = 220 - margin;
	int startX = (3 * margin) + (2 * width);
	int startY = screenHeight - 220;
	
	// Draw the holder rectangle

	// Set render color to medium grey
    SDL_SetRenderDrawColor(renderer, 65, 65, 65, 255 );

	SDL_Rect* mainRect = new SDL_Rect();
	mainRect->x = startX;
	mainRect->y = startY;
	mainRect->w = width;
	mainRect->h = height;
	SDL_RenderFillRect(renderer, mainRect);

	// Set render color to dark grey
    SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255 );

	SDL_Rect* pictureRect = new SDL_Rect();
	pictureRect->x = startX + (width / 2) - (margin / 2);
	pictureRect->y = startY + margin;
	pictureRect->w = width / 2 - (margin / 2);
	pictureRect->h = height - (2 * margin);
	SDL_RenderFillRect(renderer, pictureRect);	
}

void GUI::drawOptions()
{
	int width = (screenWidth - (4 * margin)) / 3;
	int height = 220 - margin;
	int startX = width + (2 * margin);
	int startY = screenHeight - 220;
	
	// Set render color to medium grey
    SDL_SetRenderDrawColor(renderer, 65, 65, 65, 255 );

	SDL_Rect* mainRect = new SDL_Rect();
	mainRect->x = startX;
	mainRect->y = startY;
	mainRect->w = width;
	mainRect->h = height;
	SDL_RenderFillRect(renderer, mainRect);

	// Set render color to medium grey
	SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255 );	
	
	width = (220 - (5 * margin)) / 3;
	height = width;
	for(int col = 0; col < 3 * width; col+=width + margin)
	{
		for(int row = 0; row < 3 * height; row += height + margin)
		{
			SDL_Rect* invRect = new SDL_Rect();
			invRect->x = startX + row + margin;
			invRect->y = startY + col + margin;
			invRect->w = width;
			invRect->h = height;
			SDL_RenderFillRect(renderer, invRect);
		}
	}	
}

void GUI::drawStats(int x, int y, int w, int h, Character c)
{
	TTF_Font* font = TTF_OpenFont("TerminusTTF-4.39.ttf", 18);
	if(font == NULL)
	{
		cerr << "Font error: " << TTF_GetError() << endl;
		TTF_Quit();
		SDL_Quit();
		exit(0);
	}
	SDL_Color textColor = {255, 255, 255};
	
	for(int i = 0; i < 6; i++)
	{
		std::string message;
		switch(i)
		{
			case 0 : 
				message = c.getName();
				break;
			case 1 :
				message = "STR: " + std::to_string(c.getStrength());
				break;
			case 2 :
				message = "AGL: " + std::to_string(c.getAgility());
				break;
			case 3 :
				message = "END: " + std::to_string(c.getEndurance());
				break;
			case 4 : 
				message = "CHA: " + std::to_string(c.getCharisma());
				break;
			case 5 :
				message = "HP: " + std::to_string(c.getHealth()); 
				break;
			default:
				message = "";
				break;
		}
		SDL_Surface* surface = TTF_RenderText_Solid(font, message.c_str(), textColor);
		if(surface == NULL)
		{
			cerr << "Surface error: " << TTF_GetError() << endl;
			TTF_Quit();
			SDL_Quit();
			exit(1);
		}
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

		SDL_Rect* title = new SDL_Rect();
		title->x = x + (2 * margin) + w;
		title->y = y + ((h / 6) * i);
		title->w = w;
		title->h = h / 6;

		SDL_RenderCopy(renderer,texture, NULL, title);
	}

	flush();

	//SDL_DestroyTexture(texture);
	//SDL_FreeSurface(surface);
	//TTF_CloseFont(font);
}

void GUI::drawGameScreen()
{
	int startX = margin;
	int startY = margin;
	int width = screenWidth - (2 * margin);
	int height = screenHeight - 220 - (2 * margin);
	
	// Set render color to dark grey
    SDL_SetRenderDrawColor(renderer, 65, 65, 65, 255 );

	SDL_Rect* mainRect = new SDL_Rect();
	mainRect->x = startX;
	mainRect->y = startY;
	mainRect->w = width;
	mainRect->h = height;
	SDL_RenderFillRect(renderer, mainRect);
}