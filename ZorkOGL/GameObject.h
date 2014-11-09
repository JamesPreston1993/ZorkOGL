#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

using std::string;

class GameObject
{
public:
	// Each GameObject has an ID that determines what it is and what it does
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
		MAP,
		TREASURE,
		
		// Default
		NONE
	};
	
	// No args constructor
	GameObject();	
	
	// Pure virtual destructor to make class abstract
	virtual  ~GameObject() = 0;

	// Get and set X coordinates
	int getX();
	void setX(const int x);
	
	// Get and set Y coordinates
	int getY();
	void setY(const int y);
	
	// Get and set width of GameObject
	int getWidth();
	void setWidth(const int width);
	
	// Get and set height of GameObject
	int getHeight();
	void setHeight(const int height);
	
	// Get and set ID of GameObject
	ID getID();
	void setID(const ID id);
	
	// Renders the GameObject to screen
	void draw(SDL_Renderer* const renderer);
	
	// Checks if the mouse is inside the bounding box of the GameObject
	bool mouseInside(const int mouseX, const int mouseY);

private:
	int x;
	int y;
	int width;
	int height;	
	ID id;
};

