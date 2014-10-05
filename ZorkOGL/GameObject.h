#pragma once
#include <SDL.h>
class GameObject
{
public:
	enum ID
	{
		// Characters
		PLAYER = 0,
		GUARD,
		BANDIT,
		BOSS,
		// Items
		KEY,
		SWORD,
		HAND,
		EYE,
		MAP,
		FLASK,
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
	void getHeight(int height);
	ID getID();
	void setID(ID id);	
	SDL_Rect* getBounds();				
private:
	int x;
	int y;
	int width;
	int height;	
	ID id;
	SDL_Rect* bounds;
};

