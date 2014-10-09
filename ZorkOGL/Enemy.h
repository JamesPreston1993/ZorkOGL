#pragma once
#include "character.h"
#include <string>

class Enemy :
	public Character
{
public:
	Enemy();
	Enemy(std::string name, ID id);
	~Enemy(void);
};

