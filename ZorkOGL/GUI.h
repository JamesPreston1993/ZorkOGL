#pragma once
#include "Player.h"
#include "InventoryItem.h"
#include <SDL_ttf.h>
#include "Scene.h"

class GUI
{
public:
	GUI(const int width, const int height);
	virtual ~GUI();
	
	void setupWindow();
	void setupRenderer();
	void drawCharacter(Character* const character);
	void drawCharacter();
	void drawInventory(Player* const player);
	void drawGameScreen(Scene* const currentScene);
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
	void drawControls(const int x, const int y, const int width, const int height, Player* const player);
	void drawStats(const int x, const int y, const int w, const int h, Character* const c);
};
