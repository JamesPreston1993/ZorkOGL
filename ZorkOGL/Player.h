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
private:
	std::vector<InventoryItem> inventory;
};

