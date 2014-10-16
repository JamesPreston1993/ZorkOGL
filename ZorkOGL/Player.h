#pragma once
#include "character.h"
#include "InventoryItem.h"
#include <vector>

class Player :
	public Character
{
public:
	Player();
	Player(std::string name, int strength, int agility, int endurance, int charisma);
	~Player(void);
	void addToInventory(InventoryItem item);
	std::vector<InventoryItem> getInventory();
	InventoryItem getCurrentItem();
	int getCurrentItemIndex();
	void setCurrentItemIndex(int offset);
private:
	std::vector<InventoryItem> inventory;
	InventoryItem currentItem;
	int currentItemIndex;
};

