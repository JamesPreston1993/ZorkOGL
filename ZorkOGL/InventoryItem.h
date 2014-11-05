#pragma once
#include <string>
#include "GameObject.h"

using std::string;

class InventoryItem : public GameObject
{
public:
	InventoryItem();
	InventoryItem(ID id);
	~InventoryItem(void);
	
	void drawToHUD(SDL_Renderer* renderer, int x, int y, int size);
	string getName();

private:
	string name;
	int weight;
	int value;
};

