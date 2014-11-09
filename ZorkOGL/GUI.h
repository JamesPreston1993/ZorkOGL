#pragma once
#include "Player.h"
#include "InventoryItem.h"
#include <SDL_ttf.h>
#include "Scene.h"

class GUI
{
public:
	// Constructor that takes screen width and screen height as paramaters
	GUI(const int width, const int height);

	// Virtual destructor that destroys the window and renderer - must be implemented
	virtual ~GUI();
	
	// Sets up the game window
	void setupWindow();

	// Sets up the renderer
	void setupRenderer();
	
	// Draw character information to HUD
	void drawCharacter(Character* const character);
	
	// Draws an empty character panel to HUD
	void drawCharacter();

	// Draw player's inventory to HUD
	void drawInventory(Player* const player);
	
	// Draw the game screen
	void drawGameScreen(Scene* const currentScene);
	
	// Flush the renderer
	void flush();
	
	// Clear the renderer
	void clear();

private:
	// Screen width and height
	int screenWidth;
	int screenHeight;
	
	// HUD panel width and height
	int panelWidth; 
    int panelHeight;
	
	// Margin between panels
	static const short margin = 5;
	
	// Game Window
	SDL_Window* window;

	// Renderer
	SDL_Renderer* renderer;
	
	// Draw the user controls to HUD
	void drawControls(const int x, const int y, const int width, const int height, Player* const player);
	
	// Draw the character's stats to HUD
	void drawStats(const int x, const int y, const int w, const int h, Character* const c);
};
