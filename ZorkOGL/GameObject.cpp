#include "GameObject.h"

// No args constructor sets all values to 0 and sets the ID to NONE
GameObject::GameObject()
{
	x = y = width = height = 0;
	id = NONE;
}

// Pure virtual destructor to make the class abstract
GameObject::~GameObject()
{
	// Does nothing
}

// Returns X coordinate
int GameObject::getX()
{
	return this->x;
}

// Sets X coordinate
void GameObject::setX(const int x)
{
	// If the X coordinate is inside the game screen coordinates, set x
	// Otherwise set it to lower or upper bounds depending on the value of x
	if(x >= 0 && x <= 1280 - width)
		this->x = x;
	else
	{
		if(x < 0)
			this->x = 0;
		else
			this->x = 1280 - width;
	}
}

// Returns Y coordinate
int GameObject::getY()
{
	return this->y;
}

// Sets Y Coordinate
void GameObject::setY(const int y)
{
	this->y = y;
}

// Returns width of the GameObject
int GameObject::getWidth()
{
	return this->width;
}

// Sets width of the GameObject
void GameObject::setWidth(const int width)
{
	this->width = width;
}

// Returns height of the GameObject
int GameObject::getHeight()
{
	return this->height;
}

// Sets height of the GameObject
void GameObject::setHeight(const int height)
{
	this->height = height;
}

// Returns the ID of the GameObject
GameObject::ID GameObject::getID()
{
	return this->id;
}

// Sets the ID of the GameObject
void GameObject::setID(const ID id)
{
	this->id = id;
	
	// The attributes of the object are determined by the ID
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
			x = 540;
			y = 300;
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

// Render th GameObject to screen
void GameObject::draw(SDL_Renderer* const renderer)
{
	string imagePath = "images/";
	
	// Set the file path to the image based on the ID of the object
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
		case MAP:
			imagePath += "map.gif";	break;
		case SWORD : 
			imagePath += "sword.gif"; break;
		case TREASURE : 
			imagePath += "treasureChest.gif"; break;
	}

	// Create a rectangle (bounding box) on screen
	SDL_Rect* pictureRect = new SDL_Rect();
	pictureRect->x = x;
	pictureRect->y = y;
	pictureRect->w = width;
	pictureRect->h = height;
	
	// Load the image to a surface
	SDL_Surface* image = IMG_Load(imagePath.c_str());
	if (image == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", SDL_GetError(), NULL);
		exit(0);
	}

	// Create a texture from the image
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
	
	// Free the surface to free up memory
	SDL_FreeSurface(image);
	
	// Render to screen
	SDL_RenderCopy(renderer,texture, NULL, pictureRect);
	
	// Destroy the texture and delete the bounding box to free up memory
	SDL_DestroyTexture(texture);
	delete pictureRect;
}

// CHecks if the mouse is inside the bounding box
bool GameObject::mouseInside(int mouseX, int mouseY)
{
	if(mouseX > x && mouseX < (x + width) &&
		mouseY > y && mouseY < (y + height))
	{
		return true;
	}
	return false;
}