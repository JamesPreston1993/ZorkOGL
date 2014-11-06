#pragma once
#include "Enemy.h"
#include "Scene.h"

class Game
{
public:
	Game();
	virtual ~Game();
	
	virtual void run();
	void setStateChanged(const bool state);
	void setEnemySelected(const bool selected);
	bool getEnemySelected();
	Player* getPlayer();
	Enemy* getOpponent();
	void setCurrentScene(const Scene::SceneID nextScene);
	Scene* getCurrentScene();

private:
	bool isRunning;
	Player* player;
	Enemy* enemy;
	bool stateChanged;
	bool enemySelected;
	Scene* currentScene;
};

