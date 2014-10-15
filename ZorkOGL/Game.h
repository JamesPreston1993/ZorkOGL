#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"

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
	void setCurrentScene(Scene::SceneID nextScene);
	Scene* getCurrentScene();
private:
	bool isRunning;
	Player* player;
	Enemy* enemy;
	bool stateChanged;
	bool enemySelected;
	Scene* currentScene;
};

