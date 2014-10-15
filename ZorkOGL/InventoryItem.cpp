#include "InventoryItem.h"

InventoryItem::InventoryItem() : GameObject()
{
}

InventoryItem::InventoryItem(ID id) : GameObject()
{
	switch(id)
	{
		case KEY:
			this->setID(id);
			this->name = "Key";
			this->weight = 1;
			this->value = 0;
			break;
		case HAND :
			this->setID(id);
			this->name = "Hand";
			this->weight = 0;
			this->value = 0;
			break;
		case EYE:
			this->setID(id);
			this->name = "Eye";
			this->weight = 0;
			this->value = 0;
			break;
		case MAP:
			this->setID(id);
			this->name = "Map";
			this->weight = 0;
			this->value = 0;
			break;
	}
}

InventoryItem::~InventoryItem(void)
{
}

void InventoryItem::drawToHUD(SDL_Renderer* renderer, int x, int y, int size)
{
	std::string imagePath = "images/";
	switch(this->getID())
	{
		case KEY : 
			imagePath += "key.bmp"; break;
		case HAND : 
			imagePath += "hand.bmp"; break;
		case EYE : 
			imagePath += "eye.bmp"; break;
		case MAP : 
			imagePath += "map.bmp"; break;
	}

	SDL_Rect* pictureRect = new SDL_Rect();
	pictureRect->x = x;
	pictureRect->y = y;
	pictureRect->w = size;
	pictureRect->h = size;
	
	SDL_Surface* image = SDL_LoadBMP(imagePath.c_str());
	if (image == NULL)
	{
		exit(0);
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	SDL_RenderCopy(renderer,texture, NULL, pictureRect);
	SDL_DestroyTexture(texture);
	delete pictureRect;

}