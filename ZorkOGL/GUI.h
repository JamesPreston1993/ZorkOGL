#pragma once
#include <SDL.h>
#include "Player.h"
#include "GameObject.h"
#include "InventoryItem.h"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include "Scene.h"

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
	void drawGameScreen(Scene* currentScene);
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
