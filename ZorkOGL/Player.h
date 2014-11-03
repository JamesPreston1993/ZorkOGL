#pragma once
#include "character.h"
#include "InventoryItem.h"
#include <vector>

class Player :
	public Character
{
public:
	Player();
	Player(std::string name, int strength, int agility, int endurance, int luck);
	~Player(void);
	void addToInventory(InventoryItem item);
	std::vector<InventoryItem> getInventory();
	InventoryItem getCurrentItem();
	int getCurrentItemIndex();
	void setCurrentItemIndex(int offset);
	bool isBlocking();
	void setBlocking(bool blocking);
private:
	std::vector<InventoryItem> inventory;
	InventoryItem currentItem;
	int currentItemIndex;
	bool blocking;
};

