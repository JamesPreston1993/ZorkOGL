#pragma once
#include "Character.h"
#include "InventoryItem.h"
#include <vector>

using std::vector;

class Player : public Character
{
public:
	// Constructor that takes the players name and stats
	Player(const string name, const int strength, const int agility, const int endurance, const int luck);
	
	// Adds an item to the player's inventory
	void addToInventory(const InventoryItem item);
	
	// Return the player's inventory
	vector<InventoryItem> getInventory();
	
	// Returns the current inventory item
	InventoryItem getCurrentItem();

	// Returns the index of the player's current item
	int getCurrentItemIndex();

	// Changes the index of the current item by the offset, basically changing the current item
	void setCurrentItemIndex(const int offset);

private:
	vector<InventoryItem> inventory;
	InventoryItem currentItem;
	int currentItemIndex;
};

