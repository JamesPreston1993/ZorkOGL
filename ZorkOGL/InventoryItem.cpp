#include "InventoryItem.h"


InventoryItem::InventoryItem()
{
}

InventoryItem::InventoryItem(std::string name, int weight, int value)
{
	this->name = name;
	this->value = value;
	this->weight = weight;

	if(name == "Key")
	{
		this->itemImage = "images/key.bmp";
	}
}

InventoryItem::~InventoryItem(void)
{
}

std::string InventoryItem::getItemImage()
{
	return this->itemImage;
}
