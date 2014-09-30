#pragma once
#include "SDL_opengl.h"
#include "Player.h"
class GUI
{
public:
	GUI(GLint width, GLint height);
	~GUI(void);
	void setupWindow();
	void setupRenderer();	
	void drawPlayer(Player player);
	void drawOpponent();
	void drawOptions();
	void drawGameScreen();
	void flush();
	void clear();
private:
	GLint screenWidth;
	GLint screenHeight;
	GLint margin;
};

