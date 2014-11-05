#include "Character.h"

Character::Character() : GameObject()
{
	this->name = "";
	this->strength = 1;
	this->endurance = 1;
	this->agility = 1;
	this->luck = 1;
	this->health = 100;
}
Character::Character(string name, int strength, int agility, int endurance, int luck) : GameObject()
{
	this->name = name;
	this->strength = strength;
	this->endurance = endurance;
	this->agility = agility;
	this->luck = luck;
	this->health = 100;
}

Character::~Character()
{

}

string Character::getName()
{
	return this->name;
}

void Character::setName(string name)
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

int Character::getLuck()
{
	return this->luck;
}

void Character::setLuck(int luck)
{
	this->luck = luck;
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

std::string Character::getHUDImage()
{
	return image;
}
void Character::setHUDImage(string image)
{
	this->image = image;
}