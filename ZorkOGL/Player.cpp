#include "Player.h"

Player::Player() : Character()
{
}

Player::Player(std::string name, int strength, int agility, int endurance, int charisma) : Character(name, strength, agility, endurance, charisma)
{
	this->setID(PLAYER);
	this->setHUDImage("images/playerImg.bmp");
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