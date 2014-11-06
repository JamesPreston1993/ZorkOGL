#include "Scene.h"

Scene::Scene()
{
	
}

Scene::Scene(const SceneID id)
{
	this->id = id;
	enemy = NULL;
	switch(id)
	{
		case(START) :
			name = "START";
			image = "images/start.bmp";
			items.push_back(InventoryItem(GameObject::SWORD));
			nextScene = SceneID::GATES;
			break;
		case(GATES) :
			name = "CASTLE GATES";
			image = "images/gates.bmp";
			enemy = new Enemy("HIGRON", GameObject::GUARD);
			items.push_back(InventoryItem(GameObject::MAP));
			nextScene = SceneID::TOWER;
			break;
		case(TOWER) :
			name = "GUARD TOWER";
			image = "images/tower.bmp";
			enemy = new Enemy("TALION", GameObject::GUARD);
			nextScene = SceneID::BARRACKS;
			break;
		case(BARRACKS) :
			name = "GUARD BARRACKS";
			image = "images/barracks.bmp";
			items.push_back(InventoryItem(GameObject::KEY));
			enemy = new Enemy("DURIN", GameObject::GUARD);
			nextScene = SceneID::COURTYARD;
			break;
		case(COURTYARD) :
			name = "COURTYARD";
			image = "images/courtyard.bmp";
			enemy = new Enemy("ROGHAR", GameObject::CAPTAIN);
			nextScene = SceneID::MAIN_HALL;
			break;
		case(MAIN_HALL) :
			name = "CASTLE HALL";
			image = "images/hall.bmp";
			enemy = new Enemy("SAURON", GameObject::BOSS);
			nextScene = SceneID::TREASURE_ROOM;
			break;
		case(TREASURE_ROOM) :
			name = "TREASURE ROOM";
			image = "images/hall.bmp";
			items.push_back(InventoryItem(GameObject::TREASURE));
			nextScene = SceneID::TREASURE_ROOM;
			break;
		case(GAMEOVER) :
			name = "GAME OVER";
			image = "images/gameOver.bmp";
			nextScene = SceneID::GAMEOVER;
			break;
	}
}


Scene::~Scene()
{
	if(enemy != NULL)
		delete enemy;
}

void Scene::drawScene(SDL_Renderer* const renderer, SDL_Rect* const view)
{
	SDL_Surface* bkImage = SDL_LoadBMP(image.c_str());
	SDL_Texture* bkTexture = SDL_CreateTextureFromSurface(renderer, bkImage);
	SDL_FreeSurface(bkImage);
	SDL_RenderCopy(renderer,bkTexture, NULL, view);
	SDL_DestroyTexture(bkTexture);

	if(hasItems())
	{
		for(int i = 0; i < items.size(); i++)
		{
			items.at(i).draw(renderer);
		}
	}

	if(hasEnemies())
	{
		enemy->draw(renderer);
	}
}

Scene::SceneID Scene::getID()
{
	return id;
}

Enemy* Scene::getEnemy()
{
	return enemy;
}

bool Scene::hasEnemies()
{
	if(enemy == NULL || enemy->getID() == GameObject::NONE)
	{
		return false;
	}
	return true;
}

bool Scene::hasItems()
{
	if(items.size() == 0)
	{
		return false;
	}
	return true;
}

std::vector<InventoryItem> Scene::getItems()
{
	return items;
}

void Scene::removeItem(InventoryItem item)
{
	for(int i = 0; i < items.size(); i++)
	{
		if(items.at(i).getID() == item.getID())
		{
			items.erase(items.begin() + i);
			break;
		}
	}
}

void Scene::removeEnemy(Enemy* enemy)
{
	enemy->setID(GameObject::NONE);
}

Scene::SceneID Scene::getNextScene()
{
	return nextScene;
}

string Scene::getName()
{
	return name;
}

bool Scene::isComplete()
{
	if(!hasEnemies() && !hasItems())
		return true;
	return false;
}