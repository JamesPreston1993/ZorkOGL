#pragma once
#include "Player.h"
#include "Character.h"
class Game
{
public:
	Game(void);
	virtual ~Game(void);
	virtual void run();
	void setStateChanged(bool state);
	Player* getPlayer();
	Character* getOpponent();
private:
	bool isRunning;		
};

