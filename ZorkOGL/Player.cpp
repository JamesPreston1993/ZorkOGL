#include "Player.h"

Player::Player() : Character()
{
}

Player::Player(std::string name, int strength, int agility, int endurance, int charisma) : Character(name, strength, agility, endurance, charisma)
{
	setImage("images/playerImg.bmp");
}


Player::~Player(void)
{
}
