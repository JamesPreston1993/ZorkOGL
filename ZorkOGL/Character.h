#pragma once
#include <string>
#include "GameObject.h"

using std::string;

class Character : public GameObject
{
public:
	Character();
	Character(string name, int strength, int agility, int endurance, int luck);
	virtual ~Character() = 0;

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
	string getName();
	void setName(string name);

	// Get & Set Health
	int getHealth();
	void setHealth(int health);

	// Get & Set Image
	string getHUDImage();
	void setHUDImage(string image);

private:
	// Skills
	string name;
	int strength;
	int agility;
	int endurance;
	int luck;		
	int health;
	string image;
};

