#include "GameObject.h"
#include <string>

GameObject::GameObject()
{
	x = y = width = height = 0;
	id = NONE;
}

GameObject::~GameObject()
{
}

int GameObject::getX()
{
	return this->x;
}

void GameObject::setX(int x)
{
	this->x = x;
}

int GameObject::getY()
{
	return this->y;
}

void GameObject::setY(int y)
{
	this->y = y;
}

int GameObject::getWidth()
{
	return this->width;
}

void GameObject::setWidth(int width)
{
	this->width = width;
}

int GameObject::getHeight()
{
	return this->height;
}

void GameObject::setHeight(int height)
{
	this->height = height;
}

GameObject::ID GameObject::getID()
{
	return this->id;
}

void GameObject::setID(ID id)
{
	this->id = id;
}

void GameObject::draw(SDL_Renderer* renderer)
{
	std::string imagePath = "images/";
	switch(id)
	{
		case PLAYER : 
			imagePath += "playerImg.bmp"; break;
		case GUARD :
			imagePath += "enemyImg.bmp"; break;
		case CAPTAIN : 
			imagePath += "enemyImg.bmp"; break;
		case BOSS :
			imagePath += "enemyImg.bmp"; break;
		case KEY : 
			imagePath += "key.bmp"; break;
		
		// TODO: Other items
	}

	SDL_Rect* pictureRect = new SDL_Rect();
	pictureRect->x = x;
	pictureRect->y = y;
	pictureRect->w = width;
	pictureRect->h = height;
	
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