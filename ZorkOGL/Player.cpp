#include "Player.h"

Player::Player() : Character()
{
}

Player::Player(std::string name, int strength, int agility, int endurance, int charisma) : Character(name, strength, agility, endurance, charisma)
{
	this->setID(PLAYER);
	this->setHUDImage("images/playerImg.bmp");
	// Add items to inventory
	this->inventory.push_back(InventoryItem(GameObject::HAND));
	this->inventory.push_back(InventoryItem(GameObject::EYE));
	//this->inventory.push_back(InventoryItem(GameObject::KEY));
	this->currentItem = inventory.at(0);
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