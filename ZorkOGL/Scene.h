#pragma once
#include <vector>
#include "InventoryItem.h"
#include "Enemy.h"
#include <SDL_image.h>
#include <SDL.h>

using std::string;
using std::vector;

class Scene
{
public:
	// Each Scene has an ID that determines the background and what enemies and items it contains
	enum SceneID
	{
		START = 0,
		GATES,
		TOWER,
		COURTYARD,
		BARRACKS,
		MAIN_HALL,
		TREASURE_ROOM,
		GAMEOVER
	};
	
	// Constructor that takes a SceneID
	Scene(const SceneID id);
	
	// Virtual destructor that deletes the scene's enemy - must be implemented
	virtual ~Scene();

	// Draw the scene to the screen
	void drawScene(SDL_Renderer* const renderer, SDL_Rect* const view);
	
	// Return the scene's ID
	SceneID getID();
	
	// Returns the items that exist in the scene
	vector<InventoryItem> getItems();
	
	// Returns a pointer to the enemy in the scene
	Enemy* getEnemy();
	
	// Checks if there are enemies in the scene
	bool hasEnemies();

	// Checks if there are items in the scene
	bool hasItems();

	// Removes the enemy from the scene
	void removeEnemy(Enemy* const enemy);
	
	// Removes an item from the scene
	void removeItem(InventoryItem item);
	
	// Returns the SceneID of the scene that follows this one
	SceneID getNextScene();
	
	// Returns the name of the scene
	string getName();
	
	// Check if a scene is complete
	bool isComplete();

private:
	string name;
	string image;
	vector<InventoryItem> items;
	Enemy* enemy;
	SceneID id;
	SceneID nextScene;
};

