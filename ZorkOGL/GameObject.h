#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

using std::string;

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
	virtual  ~GameObject() = 0;

	int getX();
	void setX(const int x);
	int getY();
	void setY(const int y);
	int getWidth();
	void setWidth(const int width);
	int getHeight();
	void setHeight(const int height);
	ID getID();
	void setID(const ID id);
	void draw(SDL_Renderer* const renderer);
	bool mouseInside(const int mouseX, const int mouseY);
private:
	int x;
	int y;
	int width;
	int height;	
	ID id;
};

