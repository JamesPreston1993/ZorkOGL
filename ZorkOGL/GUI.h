#pragma once
#include <SDL.h>
#include "SDL_opengl.h"
#include "Player.h"
class GUI
{
public:
	GUI(int width, int height);
	virtual ~GUI(void);
	void setupWindow();
	void setupRenderer();
	void drawCharacter(Character* character);
	void drawCharacter();
	void drawInventory(Player* player);
	void drawGameScreen();		
	void flush();
	void clear();

private:
	int screenWidth;
	int screenHeight;
	int panelWidth; 
    int panelHeight;
	static const short margin = 5;
	SDL_Window* window;
	SDL_Renderer* renderer;
	void drawStats(int x, int y, int w, int h, Character* c);
};
