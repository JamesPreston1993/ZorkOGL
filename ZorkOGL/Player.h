#pragma once
#include "character.h"
class Player :
	public Character
{
public:
	Player();
	Player(std::string name, int strength, int agility, int endurance, int charisma);
	~Player(void);
};

