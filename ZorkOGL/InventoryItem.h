#pragma once
#include "GameObject.h"

using std::string;

class InventoryItem : public GameObject
{
public:
	// No args constructor
	InventoryItem();

	// Constructor that passes in the ID of the InventoryItem
	InventoryItem(const ID id);
	
	// Draw the items in the inventory panel on screen
	void drawToHUD(SDL_Renderer* const renderer, const int x, const int y, const int size);
	
	// Return the name of the item
	string getName();

private:
	string name;
	int weight;
	int value;
};

