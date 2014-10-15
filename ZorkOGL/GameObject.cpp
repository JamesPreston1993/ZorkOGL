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
			imagePath += "guardImgFull.bmp";
			x = 200;
			y = 140;
			height = 400;
			width = 200;
			break;
		case CAPTAIN : 
			imagePath += "captainImgFull.bmp";
			x = 400;
			y = 140;
			height = 400;
			width = 200;
			break;
		case BOSS :
			imagePath += "bossImgFull.bmp";
			x = 600;
			y = 140;
			height = 400;
			width = 200;
			break;
		case KEY : 
			imagePath += "key.bmp";
			x = 500;
			y= 400;
			width = 64;
			height = 64;
			break;
		case HAND : 
			imagePath += "hand.bmp"; break;
		case EYE : 
			imagePath += "eye.bmp"; break;
		case MAP:
			imagePath += "map.bmp";
			x = 200;
			y= 200;
			width = 64;
			height = 64;
			break;
		
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
bool GameObject::mouseInside(int mouseX, int mouseY)
{
	if(mouseX > x && mouseX < (x + width) &&
		mouseY > y && mouseY < (y + height))
	{
		return true;
	}
	return false;
}