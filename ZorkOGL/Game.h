#pragma once
#include "Player.h"
class Game
{
public:
	Game(void);
	virtual ~Game(void);
	virtual void run();
	void setStateChanged(bool state);
	Player* getPlayer();
private:
	bool isRunning;		
};

