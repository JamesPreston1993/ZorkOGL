#pragma once
#include <SDL.h>
#include "SDL_opengl.h"
#include "Player.h"
class GUI
{
public:
	GUI(int width, int height);
	~GUI(void);
	void setupWindow();
	void setupRenderer();	
	void drawPlayer(Player* player);
	void drawOpponent(Character* character);
	void drawOpponent();
	void drawOptions();
	void drawGameScreen();	
	void drawStats(int x, int y, int w, int h, Character* c);
	void flush();
	void clear();

private:
	GLint screenWidth;
	GLint screenHeight;
	GLint margin;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

