#pragma once
#include "character.h"
#include "InventoryItem.h"
#include <vector>

using std::vector;

class Player : public Character
{
public:
	Player(const string name, const int strength, const int agility, const int endurance, const int luck);
	
	void addToInventory(const InventoryItem item);
	vector<InventoryItem> getInventory();
	InventoryItem getCurrentItem();
	int getCurrentItemIndex();
	void setCurrentItemIndex(const int offset);

private:
	vector<InventoryItem> inventory;
	InventoryItem currentItem;
	int currentItemIndex;
};

