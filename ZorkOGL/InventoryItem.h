#pragma once
#include <string>
#include "GameObject.h"

class InventoryItem : public GameObject
{
public:
	InventoryItem();
	InventoryItem(ID id);
	~InventoryItem(void);

	std::string getItemImage();
private:
	std::string name;
	int weight;
	int value;
	std::string itemImage;
};

