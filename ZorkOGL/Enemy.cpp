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
		this->setHUDImage("images/guardImg.bmp");
	}
	else if(id == CAPTAIN)
	{
		this->setStrength(7);
		this->setAgility(5);
		this->setEndurance(6);
		this->setCharisma(5);
		this->setHUDImage("images/captainImg.bmp");
	}
	else if(id == BOSS)
	{
		this->setStrength(8);
		this->setAgility(2);
		this->setEndurance(7);
		this->setCharisma(9);
		this->setHUDImage("images/bossImg.bmp");
	}
}

Enemy::~Enemy()
{
}
