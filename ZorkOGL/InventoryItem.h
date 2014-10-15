#pragma once
#include <string>
#include "GameObject.h"

class InventoryItem : public GameObject
{
public:
	InventoryItem();
	InventoryItem(ID id);
	~InventoryItem(void);
	void drawToHUD(SDL_Renderer* renderer, int x, int y, int size);
private:
	std::string name;
	int weight;
	int value;
};

