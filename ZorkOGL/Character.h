#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
	// No args constructor
	Character();
	
	// Constructor with name and stats
	Character(const string name, const int strength, const int agility, const int endurance, const int luck);
	
	// Pure virtual destructor to make class abstract
	virtual ~Character() = 0;

	// Get & Set Strength
	int getStrength();
	void setStrength(const int strength);
	
	// Get & Set Agility
	int getAgility();
	void setAgility(const int agility);
	
	// Get & Set Endurance
	int getEndurance();
	void setEndurance(const int endurance);
	
	// Get & Set luck
	int getLuck();
	void setLuck(const int luck);
		
	// Get & Set Name
	string getName();
	void setName(const string name);

	// Get & Set Health
	int getHealth();
	void setHealth(const int health);

	// Get & Set Image
	string getHUDImage();
	void setHUDImage(const string image);

private:
	// Character name
	string name;
	// Character stats
	int strength;
	int agility;
	int endurance;
	int luck;		
	int health;
	// File path of HUD image
	string image;
};

