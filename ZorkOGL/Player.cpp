#include "Player.h"

// Constructor that takes the players name and stats
Player::Player(const string name, const int strength, const int agility, const int endurance, const int luck) : Character(name, strength, agility, endurance, luck)
{
	// Set the ID and the HUD image
	this->setID(PLAYER);
	this->setHUDImage("images/playerImg.bmp");
	
	// Add first item to player's inventory
	this->inventory.push_back(InventoryItem(GameObject::HAND));
	
	// Set the current item as the first item in the player's inventory
	currentItemIndex = 0;
}

// Adds an item to the player's inventory
void Player::addToInventory(const InventoryItem item)
{
	// The player can only hold a maximum of 9 items
	if(inventory.size() < 9)
	{
		// If the player has less than 9 items in their inventory add the new item
		inventory.push_back(item);
	}
}

// Return the player's inventory
std::vector<InventoryItem> Player::getInventory()
{
	return inventory;
}

// Returns the current inventory item
InventoryItem Player::getCurrentItem()
{
	return currentItem;
}

// Returns the index of the player's current item
int Player::getCurrentItemIndex()
{
	return currentItemIndex;
}

// Changes the index of the current item by the offset, basically changing the current item
void Player::setCurrentItemIndex(const int offset)
{
	// Add the offset to the current item index
	currentItemIndex += offset;
	
	// If the index is less than zero set the index to the index of the last item in the player's inventory
	// Otherwise, if the index is greater than the index of the last item in the player's inventory set the index to zero
	// This creates a circular item selection system
	if(currentItemIndex < 0)
	{
		currentItemIndex = inventory.size() - 1;		
	}
	else if(currentItemIndex > inventory.size() - 1)
	{
		currentItemIndex = 0;
	}
	
	// Set the current item to the item at the new currentItem index
	currentItem = inventory.at(currentItemIndex);
}