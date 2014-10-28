#include "Scene.h"

Scene::Scene()
{
	
}

Scene::Scene(SceneID id)
{
	this->id = id;
	enemy = NULL;
	switch(id)
	{
		case(GATES) :
			name = "CASTLE GATES";
			image = "images/stone.bmp";
			enemy = new Enemy("HIGRON", GameObject::GUARD);
			items.push_back(InventoryItem(GameObject::KEY));
			items.push_back(InventoryItem(GameObject::MAP));
			nextScene = SceneID::TOWER;
			break;
		case(TOWER) :
			name = "GUARD TOWER";
			image = "images/courtyard.bmp";
			enemy = new Enemy("HIGRON", GameObject::GUARD);
			nextScene = SceneID::BARRACKS;
			break;
		case(BARRACKS) :
			name = "GUARD BARRACKS";
			image = "images/courtyard.bmp";
			enemy = new Enemy("TALON", GameObject::GUARD);
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
			image = "images/courtyard.bmp";
			enemy = new Enemy("SAURON", GameObject::BOSS);
			nextScene = SceneID::TREASURE_ROOM;
			break;
		case(TREASURE_ROOM) :
			name = "TREASURE ROOM";
			image = "images/courtyard.bmp";
			items.push_back(InventoryItem(GameObject::TREASURE));
			nextScene = SceneID::TREASURE_ROOM;
			break;
	}
}


Scene::~Scene()
{
	if(enemy != NULL)
		delete enemy;
}

void Scene::drawScene(SDL_Renderer* renderer, SDL_Rect* view)
{
	SDL_Surface* bkImage = SDL_LoadBMP(image.c_str());
	SDL_Texture* bkTexture = SDL_CreateTextureFromSurface(renderer, bkImage);
	SDL_FreeSurface(bkImage);
	SDL_RenderCopy(renderer,bkTexture, NULL, view);
	SDL_DestroyTexture(bkTexture);

	if(hasEnemies())
	{
		enemy->draw(renderer);
	}
	if(hasItems())
	{
		for(int i = 0; i < items.size(); i++)
		{
			items.at(i).draw(renderer);
		}
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
std::string Scene::getName()
{
	return name;
}

bool Scene::isComplete()
{
	if(!hasEnemies() && !hasItems())
		return true;
	return false;
}