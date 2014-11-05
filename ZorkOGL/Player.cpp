#include "Player.h"

Player::Player() : Character()
{
}

Player::Player(std::string name, int strength, int agility, int endurance, int luck) : Character(name, strength, agility, endurance, luck)
{
	this->setID(PLAYER);
	this->setHUDImage("images/playerImg.bmp");
	// Add items to inventory
	this->inventory.push_back(InventoryItem(GameObject::HAND));
	currentItemIndex = 0;
	this->currentItem = inventory.at(currentItemIndex);
}

Player::~Player(void)
{

}

void Player::addToInventory(InventoryItem item)
{
	if(inventory.size() < 9)
	{
		inventory.push_back(item);
	}
}
std::vector<InventoryItem> Player::getInventory()
{
	return inventory;
}

InventoryItem Player::getCurrentItem()
{
	return currentItem;
}

int Player::getCurrentItemIndex()
{
	return currentItemIndex;
}
void Player::setCurrentItemIndex(int offset)
{
	currentItemIndex += offset;
	if(currentItemIndex < 0)
	{
		currentItemIndex = inventory.size() - 1;		
	}
	else if(currentItemIndex > inventory.size() - 1)
	{
		currentItemIndex = 0;
	}
	currentItem = inventory.at(currentItemIndex);
}