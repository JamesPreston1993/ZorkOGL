#pragma once
#include "Enemy.h"
#include "Scene.h"

class Game
{
public:
	// No args constructor
	Game();
	// Virtual destructor - The game contains pointers that must be deleted when the Game is destroyed
	virtual ~Game();
	
	// Contains the game loop
	virtual void run();
	
	// Sets whether the game state has changed
	void setStateChanged(const bool state);

	// Sets whether there is an enemy in the current scene to attack
	void setEnemySelected(const bool selected);
	
	// Gets whether there is an enemy in the current scene to attack
	bool getEnemySelected();

	// Returns a pointer to the player
	Player* getPlayer();
	
	// Returns a pointer to the enemy in the current scene
	Enemy* getOpponent();
	
	// Sets the current scene of the game
	void setCurrentScene(const Scene::SceneID nextScene);

	// Returns a pointer to the current scene
	Scene* getCurrentScene();

private:
	bool isRunning;
	Player* player;
	Enemy* enemy;
	bool stateChanged;
	bool enemySelected;
	Scene* currentScene;
};

