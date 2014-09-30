#pragma once
#include <string>
class Character
{
public:
	Character(std::string name, int strength, int agility, int endurance, int charisma);
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
	
	// Get & Set Charisma
	int getCharisma();
	void setCharisma(int charisma);
		
	// Get & Set Name
	std::string getName();
	void setName(std::string name);

	// Get & Set Health
	int getHealth();
	void setHealth(int health);

private:
	// Skills
	std::string name;
	int strength;
	int agility;
	int endurance;
	int charisma;		
	int health;	
};

