#pragma once
#include <string>
#include "GameObject.h"

class Character : public GameObject
{
public:
	Character();
	Character(std::string name, int strength, int agility, int endurance, int luck);
	~Character(void);

	// Get & Set Strength
	int getStrength();
	void setStrength(int strength);
	
	// Get & Set Agility
	int getAgility();
	void setAgility(int agility);
	
	// Get & Set Endurance
	int getEndurance();
	void setEndurance(int endurance);
	
	// Get & Set luck
	int getLuck();
	void setLuck(int luck);
		
	// Get & Set Name
	std::string getName();
	void setName(std::string name);

	// Get & Set Health
	int getHealth();
	void setHealth(int health);

	// Get & Set Image
	std::string getHUDImage();
	void setHUDImage(std::string image);

private:
	// Skills
	std::string name;
	int strength;
	int agility;
	int endurance;
	int luck;		
	int health;
	std::string image;
};

