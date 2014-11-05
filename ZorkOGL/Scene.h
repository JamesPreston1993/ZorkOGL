#pragma once
#include <string>
#include <vector>
#include "InventoryItem.h"
#include "Enemy.h"
#include <SDL_image.h>
#include <SDL.h>

using std::string;
using std::vector;

class Scene
{
public:
	enum SceneID
	{
		START = 0,
		GATES,
		TOWER,
		COURTYARD,
		BARRACKS,
		MAIN_HALL,
		TREASURE_ROOM,
		GAMEOVER
	};
	
	Scene();
	Scene(SceneID id);
	~Scene();

	void drawScene(SDL_Renderer* renderer, SDL_Rect* view);
	SceneID getID();
	vector<InventoryItem> getItems();
	Enemy* getEnemy();
	bool hasEnemies();
	bool hasItems();
	void removeEnemy(Enemy* enemy);
	void removeItem(InventoryItem item);
	SceneID getNextScene();
	string getName();
	bool isComplete();

private:
	string name;
	string image;
	vector<InventoryItem> items;
	Enemy* enemy;
	SceneID id;
	SceneID nextScene;
};

