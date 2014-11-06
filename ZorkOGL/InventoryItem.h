#pragma once
#include "GameObject.h"

using std::string;

class InventoryItem : public GameObject
{
public:
	InventoryItem();
	InventoryItem(const ID id);
	
	void drawToHUD(SDL_Renderer* const renderer, const int x, const int y, const int size);
	string getName();

private:
	string name;
	int weight;
	int value;
};

