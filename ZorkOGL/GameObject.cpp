#include "GameObject.h"

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

void GameObject::setX(const int x)
{
	if(x >= 0 && x <= 1280 - width)
		this->x = x;
}

int GameObject::getY()
{
	return this->y;
}

void GameObject::setY(const int y)
{
	this->y = y;
}

int GameObject::getWidth()
{
	return this->width;
}

void GameObject::setWidth(const int width)
{
	this->width = width;
}

int GameObject::getHeight()
{
	return this->height;
}

void GameObject::setHeight(const int height)
{
	this->height = height;
}

GameObject::ID GameObject::getID()
{
	return this->id;
}

void GameObject::setID(const ID id)
{
	this->id = id;
	switch(id)
	{
		case GUARD :
			x = 200;
			y = 140;
			height = 400;
			width = 200;
			break;
		case CAPTAIN : 
			x = 400;
			y = 140;
			height = 400;
			width = 200;
			break;
		case BOSS :
			x = 600;
			y = 140;
			height = 400;
			width = 200;
			break;
		case KEY : 
			x = 500;
			y= 400;
			width = 100;
			height = 100;
			break;
		case MAP:
			x = 700;
			y = 400;
			width = 100;
			height = 100;
			break;
		case TREASURE:
			x = 600;
			y = 200;
			width = 200;
			height = 200;
			break;
		case SWORD:
			x = 520;
			y = 300;
			width = 200;
			height = 200;
			break;
	}
}

void GameObject::draw(SDL_Renderer* const renderer)
{
	string imagePath = "images/";
	switch(id)
	{
		case PLAYER : 
			imagePath += "playerImg.bmp"; break;
		case GUARD :
			imagePath += "guardImgFull.gif"; break;
		case CAPTAIN : 
			imagePath += "captainImgFull.gif"; break;
		case BOSS :
			imagePath += "bossImgFull.gif";	break;
		case KEY : 
			imagePath += "key.gif";	break;
		case HAND : 
			imagePath += "hand.gif"; break;
		case EYE : 
			imagePath += "eye.gif"; break;
		case MAP:
			imagePath += "map.gif";	break;
		case SWORD : 
			imagePath += "sword.gif"; break;
		case TREASURE : 
			imagePath += "treasureChest.gif"; break;
	}

	SDL_Rect* pictureRect = new SDL_Rect();
	pictureRect->x = x;
	pictureRect->y = y;
	pictureRect->w = width;
	pictureRect->h = height;
	
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
bool GameObject::mouseInside(int mouseX, int mouseY)
{
	if(mouseX > x && mouseX < (x + width) &&
		mouseY > y && mouseY < (y + height))
	{
		return true;
	}
	return false;
}