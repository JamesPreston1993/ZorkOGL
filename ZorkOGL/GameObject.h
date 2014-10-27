#pragma once
#include <SDL.h>
#include <SDL_image.h>

class GameObject
{
public:
	enum ID
	{
		// Characters
		PLAYER = 0,
		GUARD,
		CAPTAIN,
		BOSS,
		// Items
		KEY,
		SWORD,
		HAND,
		EYE,
		MAP,
		TREASURE,
		// Default
		NONE
	};
	GameObject();	
	~GameObject();

	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	int getWidth();
	void setWidth(int width);
	int getHeight();
	void setHeight(int height);
	ID getID();
	void setID(ID id);
	void draw(SDL_Renderer* renderer);
	bool mouseInside(int mouseX, int mouseY);
private:
	int x;
	int y;
	int width;
	int height;	
	ID id;
};

