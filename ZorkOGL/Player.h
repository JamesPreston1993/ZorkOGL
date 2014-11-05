#pragma once
#include "character.h"
#include "InventoryItem.h"
#include <vector>

using std::vector;

class Player : public Character
{
public:
	Player();
	Player(string name, int strength, int agility, int endurance, int luck);
	~Player(void);
	
	void addToInventory(InventoryItem item);
	vector<InventoryItem> getInventory();
	InventoryItem getCurrentItem();
	int getCurrentItemIndex();
	void setCurrentItemIndex(int offset);

private:
	vector<InventoryItem> inventory;
	InventoryItem currentItem;
	int currentItemIndex;
};

