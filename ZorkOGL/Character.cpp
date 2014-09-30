#include "Character.h"
#include <string>

Character::Character(std::string name, int strength, int agility, int endurance, int charisma)
{
	this->name = name;
	this->strength = strength;
	this->endurance = endurance;
	this->agility = agility;
	this->charisma = charisma;
	this->health = 100;	
}

Character::~Character(void)
{
}

std::string Character::getName()
{
	return this->name;
}

void Character::setName(std::string name)
{
	this->name = name;
}

int Character::getStrength()
{
	return this->strength;
}

void Character::setStrength(int strength)
{
	this->strength = strength;
}

int Character::getAgility()
{
	return this->agility;
}

void Character::setAgility(int agility)
{
	this->agility = agility;
}

int Character::getEndurance()
{
	return this->endurance;
}

void Character::setEndurance(int endurance)
{
	this->endurance = endurance;
}

int Character::getCharisma()
{
	return this->charisma;
}

void Character::setCharisma(int charisma)
{
	this->charisma = charisma;
}

int Character::getHealth()
{
	return this->health;
}

void Character::setHealth(int health)
{
	if (health < 0)
	{
		this->health = 0;
	}
	else
	{
		this->health = health;
	}
}