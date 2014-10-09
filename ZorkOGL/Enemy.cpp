#include "Enemy.h"


Enemy::Enemy()
{
}

Enemy::Enemy(std::string name, ID id)
{
	this->setName(name);
	this->setID(id);
	
	if(id == GUARD)
	{
		this->setStrength(3);
		this->setAgility(2);
		this->setEndurance(4);
		this->setCharisma(2);
		// TODO: Set HUD image
	}
	else if(id == BANDIT)
	{
		this->setStrength(7);
		this->setAgility(5);
		this->setEndurance(6);
		this->setCharisma(5);
		this->setHUDImage("images/enemyImg.bmp");
	}
	else if(id == BOSS)
	{
		this->setStrength(8);
		this->setAgility(2);
		this->setEndurance(7);
		this->setCharisma(9);
		// TODO: Set HUD image
	}
}

Enemy::~Enemy()
{
}
