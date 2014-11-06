#pragma once
#include "Player.h"

class Enemy : public Character
{
public:
	// Constructor to take name of enemy and their ID
	Enemy(const string name, const ID id);
	
	// Makes the enemy dodge player attacks
	void dodge();
	
	// Makes the enemy attack the player
	bool attack(Player* player);
	
	// Determines if the enemy is able to attack
	bool canAttack(const int time);
};

