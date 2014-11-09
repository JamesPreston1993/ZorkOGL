#include "Scene.h"

// Constructor that takes a SceneID
Scene::Scene(const SceneID id)
{
	// Set the id of the scene and set the enemy pointer to NULL
	this->id = id;
	enemy = NULL;
	
	// Determine the items, enemy, background and next scene based on the ID
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

// Destructor that deletes the scene's enemy
Scene::~Scene()
{
	// Delete the scene's enemy if it exists
	if(enemy != NULL)
		delete enemy;
}

// Draw the scene to the screen
void Scene::drawScene(SDL_Renderer* const renderer, SDL_Rect* const view)
{
	// Load the background image
	SDL_Surface* bkImage = SDL_LoadBMP(image.c_str());
	
	// Create a texture from the image
	SDL_Texture* bkTexture = SDL_CreateTextureFromSurface(renderer, bkImage);
	
	// Free the surface to free up memory
	SDL_FreeSurface(bkImage);

	// Render to screen
	SDL_RenderCopy(renderer,bkTexture, NULL, view);
	
	// Destory the texture to free up memory
	SDL_DestroyTexture(bkTexture);

	// If the scene has items then draw them to screen
	if(hasItems())
	{
		for(int i = 0; i < items.size(); i++)
		{
			items.at(i).draw(renderer);
		}
	}

	// If the scene has an enemy then draw them to screen
	if(hasEnemies())
	{
		enemy->draw(renderer);
	}
}

// Return the scene's ID
Scene::SceneID Scene::getID()
{
	return id;
}

// Returns the items that exist in the scene
std::vector<InventoryItem> Scene::getItems()
{
	return items;
}

// Returns a pointer to the enemy in the scene
Enemy* Scene::getEnemy()
{
	return enemy;
}

// Checks if there are enemies in the scene
bool Scene::hasEnemies()
{
	if(enemy == NULL || enemy->getID() == GameObject::NONE)
	{
		return false;
	}
	return true;
}

// Checks if there are items in the scene
bool Scene::hasItems()
{
	if(items.size() == 0)
	{
		return false;
	}
	return true;
}

// Removes an item from the scene
void Scene::removeItem(InventoryItem item)
{
	// Find the item in the scene's items and remove it
	for(int i = 0; i < items.size(); i++)
	{
		if(items.at(i).getID() == item.getID())
		{
			items.erase(items.begin() + i);
			break;
		}
	}
}

// Removes the enemy from the scene
void Scene::removeEnemy(Enemy* enemy)
{
	enemy->setID(GameObject::NONE);
}

// Returns the SceneID of the scene that follows this one
Scene::SceneID Scene::getNextScene()
{
	return nextScene;
}

// Returns the name of the scene
string Scene::getName()
{
	return name;
}

// Check if a scene is complete
bool Scene::isComplete()
{
	// If all items have been removed and all enemies killed then the scene is complete
	if(!hasEnemies() && !hasItems())
		return true;
	return false;
}