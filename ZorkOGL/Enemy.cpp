#include "Enemy.h"

// Constructor sets name and stats based on the ID
Enemy::Enemy(const string name,const  ID id) : Character()
{
	this->setName(name);
	this->setID(id);
	
	// Determines the enemy's stats based on the ID
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

// Generates a random number and if enemy's agility is greater, the enemy dodges the attack
void Enemy::dodge()
{
	int chance = rand() % 10 + 1;
	if(this->getAgility() >= chance)
	{
		// Generates a random number that determiens if the player dodges left or right
		int direction = rand() % 100 + 1;
		
		if(direction > 50)
			this->setX(this->getX() + this->getWidth());
		else
			this->setX(this->getX() - this->getWidth());
	}
}

// Generates a random number and if enemy's luck is greater, the enemy attacks the player
bool Enemy::attack(Player* player)
{
	int chance = rand() % 10 + 1;
	if(this->getLuck() >= chance)
	{
		// Subtracts the enemy's strength from the player's health
		// and return true, denoting a successful hit
		player->setHealth(player->getHealth() - this->getStrength());
		return true;
	}
	// Returns false if the enemy's attack is unsuccessful
	return false;
}

// Determines if an enemy is allowed to attack based on the time since their last attack
bool Enemy::canAttack(const int time)
{
	// The enemy's endurance determines how soon they can attack
	// A higher endurance means they can attack more often
	if(9 * (10 - this->getEndurance()) <= time)
	{
		// Returns true if the enemy can attack
		return true;
	}
	// Returns false if the enemy can't attack
	return false;
}