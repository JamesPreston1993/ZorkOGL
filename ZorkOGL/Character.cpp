#include "Character.h"

// No args constructor defaults all stats to 1
Character::Character() : GameObject()
{
	this->name = "";
	this->strength = 1;
	this->endurance = 1;
	this->agility = 1;
	this->luck = 1;
	this->health = 100;
}

// Constructor sets name and stats to the values passed in
Character::Character(const string name, const int strength, const int agility, const int endurance, const int luck) : GameObject()
{
	this->name = name;
	this->strength = strength;
	this->endurance = endurance;
	this->agility = agility;
	this->luck = luck;
	this->health = 100;
}

// Pure virtual function is implemented to make class abstract
Character::~Character()
{
	// Does nothing
}


// Returns character name
string Character::getName()
{
	return this->name;
}

// Sets character name
void Character::setName(const string name)
{
	this->name = name;
}

// Returns character strength
int Character::getStrength()
{
	return this->strength;
}

// Sets character strength
void Character::setStrength(const int strength)
{
	this->strength = strength;
}

// Returns character agility
int Character::getAgility()
{
	return this->agility;
}

// Sets character agility
void Character::setAgility(const int agility)
{
	this->agility = agility;
}

// Returns character endurance
int Character::getEndurance()
{
	return this->endurance;
}

// Sets character endurance
void Character::setEndurance(const int endurance)
{
	this->endurance = endurance;
}

// Returns character luck
int Character::getLuck()
{
	return this->luck;
}

// Sets character luck
void Character::setLuck(const int luck)
{
	this->luck = luck;
}


// Returns character health
int Character::getHealth()
{
	return this->health;
}

// Sets character health
void Character::setHealth(const int health)
{
	// If the health is below 0 set it to 0
	// If the health is above 100 set it to 100
	if (health < 0)
	{
		this->health = 0;
	}
	else if(health > 100)
	{
		this->health = 100;
	}
	else
	{
		this->health = health;
	}
}

// Returns file path of HUD image
string Character::getHUDImage()
{
	return image;
}

// Sets file path of HUD image
void Character::setHUDImage(const string image)
{
	this->image = image;
}

// Overloaded less than operator
bool operator<(const Character &a, const Character &b)
{
	// Get the total of each chracter's stats and health and compare them
	int aStats = a.strength + a.agility + a.endurance + a.luck + a.health;
	int bStats = b.strength + b.agility + b.endurance + b.luck + b.health;

	if(aStats < bStats)
		return true;
	return false;
}

// Overloaded greater than operator
bool operator>(const Character &a, const Character &b)
{
	// Get the total of each chracter's stats and health and compare them
	int aStats = a.strength + a.agility + a.endurance + a.luck + a.health;
	int bStats = b.strength + b.agility + b.endurance + b.luck + b.health;

	if(aStats > bStats)
		return true;
	return false;
}