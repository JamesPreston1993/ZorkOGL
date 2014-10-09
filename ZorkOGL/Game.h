#pragma once
#include "Player.h"
#include "Enemy.h"
class Game
{
public:
	Game(void);
	virtual ~Game(void);
	virtual void run();
	void setStateChanged(bool state);
	void setEnemySelected(bool selected);
	bool getEnemySelected();
	Player* getPlayer();
	Enemy* getOpponent();
private:
	bool isRunning;
	Player* player;
	Enemy* enemy;
	bool stateChanged;
	bool enemySelected;
};

