#include "Enemy.h"

Enemy::Enemy(string name, ID id)
{
	this->setName(name);
	this->setID(id);
	
	if(id == GUARD)
	{
		this->setStrength(3);
		this->setAgility(2);
		this->setEndurance(4);
		this->setLuck(2);
		this->setHUDImage("images/guardImg.bmp");
	}
	else if(id == CAPTAIN)
	{
		this->setStrength(5);
		this->setAgility(5);
		this->setEndurance(6);
		this->setLuck(5);
		this->setHUDImage("images/captainImg.bmp");
	}
	else if(id == BOSS)
	{
		this->setStrength(7);
		this->setAgility(8);
		this->setEndurance(7);
		this->setLuck(8);
		this->setHUDImage("images/bossImg.bmp");
	}
}

void Enemy::dodge()
{
	int chance = rand() % 10 + 1;
	if(this->getAgility() >= chance)
	{
		// Move character
		int direction = rand() % 100 + 1;
		if(direction > 50)
			this->setX(this->getX() + this->getWidth());
		else
			this->setX(this->getX() - this->getWidth());
	}
}

bool Enemy::attack(Player* player)
{
	int chance = rand() % 10 + 1;
	if(this->getLuck() >= chance)
	{
		player->setHealth(player->getHealth() - this->getLuck());
		return true;
	}
	return false;
}

bool Enemy::canAttack(int time)
{
	if(9 * (10 - this->getEndurance()) <= time)
	{
		return true;
	}
	return false;
}