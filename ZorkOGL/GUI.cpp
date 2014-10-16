#include "GUI.h"

using std::cerr;
using std::endl;

GUI::GUI(int width, int height)
{
	screenWidth = width;
	screenHeight = height;
	panelWidth = (screenWidth - (4 * margin)) / 3;
	panelHeight = (screenHeight - (3 * margin)) / 4;

	SDL_ShowCursor(SDL_DISABLE);

	setupWindow();
}

GUI::~GUI(void)
{
	clear();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
}

void GUI::setupWindow()
{
	// Set up display
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	
	// Doesn't work for multiple displays 
	//window = SDL_CreateWindow("ZorkOGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_FULLSCREEN);
	
	window = SDL_CreateWindow("ZorkOGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, 0);

	if(window == NULL)
	{
		cerr << "Window error: " << TTF_GetError() << endl;
		TTF_Quit();
		SDL_Quit();
		exit(0);
	}
	setupRenderer();
}
void GUI::setupRenderer()
{
	// Initialise renderer
	renderer =  SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);	
    
	if(renderer == NULL)
	{
		cerr << "Renderer error: " << TTF_GetError() << endl;
		TTF_Quit();
		SDL_Quit();
		exit(0);
	}

	// Set render color to dark grey
    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255 );
		
	// Flush
	flush();
}
void GUI::flush()
{
	// Flush
	SDL_RenderPresent(renderer);
}

void GUI::clear()
{
	// Clear
	SDL_RenderClear(renderer);
}

void GUI::drawCharacter(Character* character)
{
	int startX, startY;
	if(character->getID() == GameObject::PLAYER)
	{
		startX = margin;
		startY = screenHeight - panelHeight;
	}
	else
	{
		startX = (3 * margin) + (2 * panelWidth);
		startY = screenHeight - panelHeight;
	}
	
	// Draw the holder rectangle
	SDL_Rect* mainRect = new SDL_Rect();
	mainRect->x = startX;
	mainRect->y = startY;
	mainRect->w = panelWidth;
	mainRect->h = panelHeight - margin;

	SDL_Surface* bkImage = SDL_LoadBMP("images/stone2.bmp");
	if (bkImage == NULL)
	{
		cerr << "SDL_LoadBMP() Failed: " << SDL_GetError() << endl;
		exit(0);
	}
	SDL_Texture* bkTexture = SDL_CreateTextureFromSurface(renderer, bkImage);
	SDL_FreeSurface(bkImage);
	SDL_RenderCopy(renderer,bkTexture, NULL, mainRect);
	SDL_DestroyTexture(bkTexture);

	SDL_Rect* pictureRect = new SDL_Rect();
	pictureRect->x = startX + margin;
	pictureRect->y = startY + margin;
	//pictureRect->w = panelWidth / 2 - margin;
	pictureRect->w = mainRect->h - (2 * margin);
	pictureRect->h = mainRect->h - (2 * margin);
	
	SDL_Surface* image = SDL_LoadBMP(character->getHUDImage().c_str());
	if (image == NULL)
	{
		cerr << "SDL_LoadBMP() Failed: " << SDL_GetError() << endl;
		exit(0);
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	SDL_RenderCopy(renderer,texture, NULL, pictureRect);
	SDL_DestroyTexture(texture);	

	drawStats(startX, startY, pictureRect->w, pictureRect->h, character);

	delete pictureRect;
	delete mainRect;
}

void GUI::drawCharacter()
{	
	int startX = (3 * margin) + (2 * panelWidth);
	int startY = screenHeight - panelHeight;

	SDL_Rect* mainRect = new SDL_Rect();
	mainRect->x = startX;
	mainRect->y = startY;
	mainRect->w = panelWidth;
	mainRect->h = panelHeight - margin;

	SDL_Surface* bkImage = SDL_LoadBMP("images/stone2.bmp");
	if (bkImage == NULL)
	{
		cerr << "SDL_LoadBMP() Failed: " << SDL_GetError() << endl;
		exit(0);
	}
	SDL_Texture* bkTexture = SDL_CreateTextureFromSurface(renderer, bkImage);
	SDL_FreeSurface(bkImage);
	SDL_RenderCopy(renderer,bkTexture, NULL, mainRect);
	SDL_DestroyTexture(bkTexture);

	delete mainRect;
}

void GUI::drawInventory(Player* player)
{
	//int width = (screenWidth - (4 * margin)) / 3;
	//int height = panelHeight - margin;
	int startX = panelWidth + (2 * margin);
	int startY = screenHeight - panelHeight;

	SDL_Rect* mainRect = new SDL_Rect();
	mainRect->x = startX;
	mainRect->y = startY;
	mainRect->w = panelWidth;
	mainRect->h = panelHeight - margin;

	SDL_Surface* bkImage = SDL_LoadBMP("images/stone2.bmp");
	if (bkImage == NULL)
	{
		cerr << "SDL_LoadBMP() Failed: " << SDL_GetError() << endl;
		exit(0);
	}
	SDL_Texture* bkTexture = SDL_CreateTextureFromSurface(renderer, bkImage);
	SDL_FreeSurface(bkImage);
	SDL_RenderCopy(renderer,bkTexture, NULL, mainRect);
	SDL_DestroyTexture(bkTexture);

	// Set render color to medium grey
	SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255 );	
	
	int width = (panelHeight - (5 * margin)) / 3;
	int height = width;

	int inventoryIndex = 0;
	int inventorySize = player->getInventory().size();

	for(int col = 0; col < 3 * width; col+=width + margin)
	{
		for(int row = 0; row < 3 * height; row += height + margin)
		{
			if(inventoryIndex == player->getCurrentItemIndex())
			{
				SDL_SetRenderDrawColor(renderer, 255, 220, 100, 255 );
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255 );
			}			
	
			SDL_Rect* invRect = new SDL_Rect();
			invRect->x = startX + row + margin;
			invRect->y = startY + col + margin;
			invRect->w = width;
			invRect->h = height;			
			SDL_RenderFillRect(renderer, invRect);

			if(inventoryIndex < inventorySize)
			{
				player->getInventory().at(inventoryIndex).drawToHUD(renderer, invRect->x, invRect->y, width);				
			}

			inventoryIndex++;
			delete invRect;
		}
	}	
	delete mainRect;
}

void GUI::drawStats(int x, int y, int w, int h, Character* c)
{
	TTF_Font* font = TTF_OpenFont("font/TerminusTTF-4.39.ttf", 18);
	if(font == NULL)
	{
		cerr << "Font error: " << TTF_GetError() << endl;
		TTF_Quit();
		SDL_Quit();
		exit(0);
	}
	
	SDL_Color textColor = {255, 255, 255};
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;

	for(int i = 0; i < 6; i++)
	{
		std::string message;
		switch(i)
		{
			case 0 : 
				message = c->getName();
				break;
			case 1 :
				message = "STR: " + std::to_string(c->getStrength());
				break;
			case 2 :
				message = "AGL: " + std::to_string(c->getAgility());
				break;
			case 3 :
				message = "END: " + std::to_string(c->getEndurance());
				break;
			case 4 : 
				message = "CHA: " + std::to_string(c->getCharisma());
				break;
			case 5 :
				if(c->getHealth() >= 100)
					message = "HP:" + std::to_string(c->getHealth());
				else if (c->getHealth() < 10)
					message = "HP:  " + std::to_string(c->getHealth()); 
				else
					message = "HP: " + std::to_string(c->getHealth());
				break;
			default:
				message = "";
				break;
		}
		
		// Create surface
		surface = TTF_RenderText_Solid(font, message.c_str(), textColor);
		if(surface == NULL)
		{
			cerr << "Surface error: " << TTF_GetError() << endl;
			TTF_Quit();
			SDL_Quit();
			exit(0);
		}
		// Create texture and free surface as we are done with it
		texture = SDL_CreateTextureFromSurface(renderer, surface);		
		SDL_FreeSurface(surface);
		
		// Create a rectangle for the Texture
		SDL_Rect* title = new SDL_Rect();
		title->x = x + (2 * margin) + w;
		title->y = y + ((h / 6) * i);
		title->w = panelWidth - (w + margin);
		title->h = h / 6;

		// Render
		SDL_RenderCopy(renderer,texture, NULL, title);

		// Destroy the title rectangle and texture when we are done with them
		delete title;
		SDL_DestroyTexture(texture);
	}
	TTF_CloseFont(font);
}

void GUI::drawGameScreen(Scene* currentScene)
{
	int startX = margin;
	int startY = margin;
	int width = screenWidth - (2 * margin);
	int height = screenHeight - panelHeight - (2 * margin);

	SDL_Rect* mainRect = new SDL_Rect();
	mainRect->x = startX;
	mainRect->y = startY;
	mainRect->w = width;
	mainRect->h = height;

	// Create and draw scene
	currentScene->drawScene(renderer, mainRect);

	// Draw level title at top of page

	// Free resources
	delete mainRect;
}