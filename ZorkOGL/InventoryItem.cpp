#include "InventoryItem.h"

InventoryItem::InventoryItem() : GameObject()
{
}

InventoryItem::InventoryItem(ID id) : GameObject()
{
	if(id == KEY)
	{
		this->itemImage = "images/key.bmp";
		this->name = "Key";
		this->weight = 1;
		this->value = 0;
	}
}

InventoryItem::~InventoryItem(void)
{
}

std::string InventoryItem::getItemImage()
{
	return this->itemImage;
}
