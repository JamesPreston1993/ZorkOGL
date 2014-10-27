#include "InventoryItem.h"
#include <SDL_image.h>

InventoryItem::InventoryItem() : GameObject()
{
}

InventoryItem::InventoryItem(ID id) : GameObject()
{
	switch(id)
	{
		case KEY:
			this->setID(id);
			this->name = "KEY";
			this->weight = 1;
			this->value = 0;
			break;
		case HAND :
			this->setID(id);
			this->name = "HAND";
			this->weight = 0;
			this->value = 0;
			break;
		case EYE:
			this->setID(id);
			this->name = "EYE";
			this->weight = 0;
			this->value = 0;
			break;
		case MAP:
			this->setID(id);
			this->name = "MAP";
			this->weight = 0;
			this->value = 0;
			break;
		case SWORD:
			this->setID(id);
			this->name = "SWORD";
			this->weight = 5;
			this->value = 20;
			break;
		case TREASURE:
			this->setID(id);
			this->name = "GOLD";
			this->weight = 20;
			this->value = 1000;
			break;
	}
}

InventoryItem::~InventoryItem(void)
{
}

std::string InventoryItem::getName()
{
	return this->name;
}

void InventoryItem::drawToHUD(SDL_Renderer* renderer, int x, int y, int size)
{
	std::string imagePath = "images/";
	switch(this->getID())
	{
		case KEY : 
			imagePath += "key.gif"; break;
		case HAND : 
			imagePath += "hand.gif"; break;
		case EYE : 
			imagePath += "eye.gif"; break;
		case MAP : 
			imagePath += "map.gif"; break;
		case SWORD:
			imagePath += "sword.gif"; break;
		case TREASURE:
			imagePath += "treasureChest.gif"; break;
	}

	SDL_Rect* pictureRect = new SDL_Rect();
	pictureRect->x = x;
	pictureRect->y = y;
	pictureRect->w = size;
	pictureRect->h = size;

	SDL_Surface* image = IMG_Load(imagePath.c_str());
	if (image == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", SDL_GetError(), NULL);
		exit(0);
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	SDL_RenderCopy(renderer,texture, NULL, pictureRect);
	SDL_DestroyTexture(texture);
	delete pictureRect;

}