#include "GUI.h"
#include <SDL.h>
#include "SDL_opengl.h"

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
	window = SDL_CreateWindow("ZorkOGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, 0);	
}
void GUI::setupRenderer()
{
	// Initialise renderer
	renderer =  SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);	
    
	// Set render color to dark grey
    SDL_SetRenderDrawColor(renderer, 25.5, 25.5, 25.5, 255 );
		
	// Flush
	SDL_RenderPresent(renderer);
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
	pictureRect->w = width / 2 - (margin / 2);
	pictureRect->h = height - (2 * margin);
	SDL_RenderFillRect(renderer, pictureRect);
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
	
	width = (220 - (4 * margin)) / 3;
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

	/*
	GLint startX = screenWidth / 3;
	GLint startY = screenHeight - 220;
	GLint endX = 2 * (screenWidth / 3);
	GLint endY = screenHeight - margin;

	glPushMatrix();
	
	glOrtho(0, screenWidth, screenHeight ,0, -1, 1);

	glColor3f(0.25, 0.25, 0.25);
	
	glBegin(GL_QUADS);
		glVertex2f(startX + margin, startY + margin);
		glVertex2f(endX - margin, startY + margin);
		glVertex2f(endX - margin, endY - margin);
		glVertex2f(startX + margin, endY - margin);
	glEnd();	

	glColor3f(0.1, 0.1, 0.1);
	for(int col = 0; col < 3 * 64; col+=64 + margin)
	{
		for(int row = 0; row < 3 * 64; row+=64 + margin)
		{
			glBegin(GL_QUADS);
				glVertex2f(startX + row + (2 * margin), startY + col + (2 * margin));
				glVertex2f(startX + row + 64 + (2 * margin), startY + col + (2 * margin));
				glVertex2f(startX + row + 64 + (2 * margin), startY + col + 64 + (2 * margin));
				glVertex2f(startX + row + (2 * margin), startY + col + 64 + (2 * margin));
			glEnd();
		}
	}

	glPopMatrix();	
	glPushMatrix();
	
	glOrtho(0,1280,720,0,-1,1);

	glColor3f(0.25, 0.25, 0.25);
	
	glBegin(GL_QUADS);
		glVertex2f(425, 475);
		glVertex2f(845, 475);
		glVertex2f(845, 715);
		glVertex2f(425, 715);
	glEnd();

	glPopMatrix();
	*/
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

	/*
	GLint startX = 0;
	GLint startY = 0;
	GLint endX = screenWidth;
	GLint endY = screenHeight - 220;

	glPushMatrix();
	
	glOrtho(0, screenWidth, screenHeight ,0, -1, 1);

	glColor3f(0.75, 0.75, 0.75);
	
	glBegin(GL_QUADS);
		glVertex2f(startX + margin, startY + margin);
		glVertex2f(endX - margin, startY + margin);
		glVertex2f(endX - margin, endY - margin);
		glVertex2f(startX + margin, endY - margin);
	glEnd();

	glPopMatrix();

	glPushMatrix();	

	glOrtho(0,1280,720,0,-1,1);
	
	glColor3f(0.5, 0.5, 0.5);
	
	glBegin(GL_QUADS);
		glVertex2f(5, 5);
		glVertex2f(1275, 5);
		glVertex2f(1275, 470);
		glVertex2f(5, 470);
	glEnd();

	glPopMatrix();
	*/
}