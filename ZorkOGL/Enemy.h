#pragma once
#include "character.h"
#include "Player.h"
#include <string>

class Enemy : public Character
{
public:
	Enemy(std::string name, ID id);
	void dodge();
	bool attack(Player* player);
	bool canAttack(int time);
};

