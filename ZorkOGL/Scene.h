#pragma once
#include <string>
#include <vector>
#include "InventoryItem.h"
#include "Enemy.h"
#include <SDL_image.h>
#include <SDL.h>

class Scene
{
public:
	enum SceneID
	{
		GATES = 0,
		TOWER,
		COURTYARD,
		BARRACKS,
		MAIN_HALL,
		TREASURE_ROOM
	};
	Scene();
	Scene(SceneID id);
	~Scene();
	void drawScene(SDL_Renderer* renderer, SDL_Rect* view);
	SceneID getID();
	std::vector<InventoryItem> getItems();
	Enemy* getEnemy();
	bool hasEnemies();
	bool hasItems();
	void removeEnemy(Enemy* enemy);
	void removeItem(InventoryItem item);
	SceneID getNextScene();
	std::string getName();
	bool isComplete();
private:
	std::string name;
	std::string image;
	std::vector<InventoryItem> items;
	Enemy* enemy;
	SceneID id;
	SceneID nextScene;
};

