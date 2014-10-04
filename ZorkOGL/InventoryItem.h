#pragma once
#include <string>
class InventoryItem
{
public:
	InventoryItem();
	InventoryItem(std::string, int weight, int value);
	~InventoryItem(void);

	std::string getItemImage();
private:
	std::string name;
	int weight;
	int value;
	std::string itemImage;
};

