#include "GUI.h"

// Constructor that takes screen width and screen height as paramaters
GUI::GUI(const int width, const int height)
{
	screenWidth = width;
	screenHeight = height;
	
	// Set the width of each panel to roughly a third of the screen
	panelWidth = (screenWidth - (4 * margin)) / 3;
	// Set the height of each panel to roughly a quarter of the screen
	panelHeight = (screenHeight - (3 * margin)) / 4;

	// Set up the window
	setupWindow();
}

// Virtual destructor that destroys the window and renderer - must be implemented
GUI::~GUI()
{
	clear();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
}

// Sets up the game window
void GUI::setupWindow()
{
	// Initialise SDL and TTF
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	
	// Set up the window giving its position on screen and width and height
	window = SDL_CreateWindow("ZorkOGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, 0);

	// If the window cannot be set up quit the application
	if(window == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "WINDOW ERROR", SDL_GetError(), NULL);		
		TTF_Quit();
		SDL_Quit();
		exit(0);
	}

	// Set up the renderer
	setupRenderer();
}

// Sets up the renderer
void GUI::setupRenderer()
{
	// Initialise renderer
	renderer =  SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);	
    
	// If the renderer cannot be set up quit the application
	if(renderer == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "RENDERER ERROR", SDL_GetError(), NULL);
		TTF_Quit();
		SDL_Quit();
		exit(0);
	}

	// Set render color to dark grey
    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255 );
		
	// Flush
	flush();
}

// Flush the renderer
void GUI::flush()
{
	// Flush
	SDL_RenderPresent(renderer);
}

// Clear the renderer
void GUI::clear()
{
	// Clear
	SDL_RenderClear(renderer);
}

// Draw character information to HUD
void GUI::drawCharacter(Character* const character)
{
	// The X and Y co-ordinates where the panel will start drawing from
	int startX, startY;
	
	// If the charcter is a player draw on the left side of screen
	// Otherwise, draw on the right side of screen
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

	// Load the image
	SDL_Surface* bkImage = SDL_LoadBMP("images/stone2.bmp");
	if (bkImage == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "LOAD IMAGE ERROR", SDL_GetError(), NULL);
		TTF_Quit();
		SDL_Quit();
		exit(0);
	}
	
	// Create texture from image
	SDL_Texture* bkTexture = SDL_CreateTextureFromSurface(renderer, bkImage);
	
	// Free the surface to free up memory
	SDL_FreeSurface(bkImage);
	
	// Render to screen
	SDL_RenderCopy(renderer,bkTexture, NULL, mainRect);
	
	// Destroy the texture to free up memory
	SDL_DestroyTexture(bkTexture);

	// Draw the portrait rectangle
	SDL_Rect* pictureRect = new SDL_Rect();
	pictureRect->x = startX + margin;
	pictureRect->y = startY + margin;	
	pictureRect->w = mainRect->h - (2 * margin);
	pictureRect->h = mainRect->h - (2 * margin);
	
	// Load the character image
	SDL_Surface* image = SDL_LoadBMP(character->getHUDImage().c_str());
	
	// If the image can't be loaded quit the application
	if (image == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "LOAD IMAGE ERROR", SDL_GetError(), NULL);
		TTF_Quit();
		SDL_Quit();
		exit(0);
	}

	// Create texture from image
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
	
	// Free surface to free up memory
	SDL_FreeSurface(image);
	
	// Render to screen
	SDL_RenderCopy(renderer,texture, NULL, pictureRect);
	
	// Destroy texture to free up memory
	SDL_DestroyTexture(texture);	

	// Draw the character's stats
	drawStats(startX, startY, pictureRect->w, pictureRect->h, character);
	
	// Delete the rectangles to free up memory
	delete pictureRect;
	delete mainRect;
}

// Draws an empty character panel to HUD
void GUI::drawCharacter()
{	
	// The X and Y co-ordinates where the panel will start drawing from
	int startX = (3 * margin) + (2 * panelWidth);
	int startY = screenHeight - panelHeight;

	// Draw the holder rectangle
	SDL_Rect* mainRect = new SDL_Rect();
	mainRect->x = startX;
	mainRect->y = startY;
	mainRect->w = panelWidth;
	mainRect->h = panelHeight - margin;

	// Load the image
	SDL_Surface* bkImage = SDL_LoadBMP("images/stone2.bmp");
	
	// If the image can't be loaded quit the application
	if (bkImage == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "LOAD IMAGE ERROR", SDL_GetError(), NULL);
		TTF_Quit();
		SDL_Quit();
		exit(0);
	}
	
	// Create texture from image
	SDL_Texture* bkTexture = SDL_CreateTextureFromSurface(renderer, bkImage);
	
	// Free surface to free up memory
	SDL_FreeSurface(bkImage);
	
	// Render to screen
	SDL_RenderCopy(renderer,bkTexture, NULL, mainRect);
	
	// Destroy texture to free up memory
	SDL_DestroyTexture(bkTexture);

	// Delete rectangle to free up memory 
	delete mainRect;
}

// Draw player's inventory to HUD
void GUI::drawInventory(Player* const player)
{
	// The X and Y co-ordinates where the panel will start drawing from
	int startX = panelWidth + (2 * margin);
	int startY = screenHeight - panelHeight;

	// Draw the holder rectangle
	SDL_Rect* mainRect = new SDL_Rect();
	mainRect->x = startX;
	mainRect->y = startY;
	mainRect->w = panelWidth;
	mainRect->h = panelHeight - margin;

	// Load the image
	SDL_Surface* bkImage = SDL_LoadBMP("images/stone2.bmp");
	
	// If the image can't be loaded quit the application
	if (bkImage == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "LOAD IMAGE ERROR", SDL_GetError(), NULL);
		TTF_Quit();
		SDL_Quit();
		exit(0);
	}
	
	// Create texture from image
	SDL_Texture* bkTexture = SDL_CreateTextureFromSurface(renderer, bkImage);
	
	// Free surface to free up memory
	SDL_FreeSurface(bkImage);
	
	// Render to screen
	SDL_RenderCopy(renderer,bkTexture, NULL, mainRect);
	
	// Destroy texture to free up memory
	SDL_DestroyTexture(bkTexture);
	
	// Set the width and height of the inventory slot
	int width = (panelHeight - (5 * margin)) / 3;
	int height = width;

	// Set the inventory index and size
	int inventoryIndex = 0;
	int inventorySize = player->getInventory().size();

	// Draw the inventory grid
	for(int col = 0; col < 3 * width; col+=width + margin)
	{
		for(int row = 0; row < 3 * height; row += height + margin)
		{
			// If the current item is selected then set the background colour to yellow
			if(inventoryIndex == player->getCurrentItemIndex())
			{
				SDL_SetRenderDrawColor(renderer, 255, 220, 100, 255 );
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255 );
			}			
	
			// Draw the inventory rectangle
			SDL_Rect* invRect = new SDL_Rect();
			invRect->x = startX + row + margin;
			invRect->y = startY + col + margin;
			invRect->w = width;
			invRect->h = height;			
			SDL_RenderFillRect(renderer, invRect);

			// Draw the inventory item to HUD
			if(inventoryIndex < inventorySize)
			{
				player->getInventory().at(inventoryIndex).drawToHUD(renderer, invRect->x, invRect->y, width);				
			}

			// Increment index
			inventoryIndex++;

			// Delete rectangle to free up memory
			delete invRect;
		}
	}
	
	// Draw the user controls to HUD
	drawControls(mainRect->x + panelWidth / 2, mainRect->y, panelWidth / 2, panelHeight, player);
	
	// Delete rectangle to free up memory
	delete mainRect;
}

// Draw the user controls to HUD
void GUI::drawControls(const int x, const int y, const int width, const int height, Player* const player)
{
	// Load the font
	TTF_Font* font = TTF_OpenFont("font/TerminusTTF-4.39.ttf", 18);
	
	// If the font can't be loaded quit the application
	if(font == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "LOAD FONT ERROR", SDL_GetError(), NULL);
		TTF_Quit();
		SDL_Quit();
		exit(0);
	}

	// Create a text color and initialise surface and texture
	SDL_Color textColor = {255, 255, 255};
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;

	for(int i = 0; i < 3; i++)
	{
		string message;
		switch(i)
		{
			case 0 :
				message = " ITEM: ";
				break;
			case 1 : 
				message = player->getCurrentItem().getName();
				break;
			case 2 :
				message = "Z/X: NEXT";
				break;			
			default:
				message = "";
				break;
		}
		
		// Create surface
		surface = TTF_RenderText_Solid(font, message.c_str(), textColor);
		
		// If the image can't be load quit the application
		if(surface == NULL)
		{
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "LOAD SURFACE ERROR", SDL_GetError(), NULL);		
			TTF_Quit();
			SDL_Quit();
			exit(0);
		}
		
		// Create texture and free surface as we are done with it
		texture = SDL_CreateTextureFromSurface(renderer, surface);		
		SDL_FreeSurface(surface);
		
		// Create a rectangle for the Texture
		SDL_Rect* title = new SDL_Rect();
		title->x = x;
		title->y = y + ((height / 3) * i);
		title->w = width;
		title->h = height / 4;

		// Render to screen
		SDL_RenderCopy(renderer,texture, NULL, title);

		// Destroy the title rectangle and texture when we are done with them
		delete title;
		SDL_DestroyTexture(texture);
	}
	
	// Close the font to free up memory
	TTF_CloseFont(font);
}

// Draw the character's stats to HUD
void GUI::drawStats(int x, int y, int w, int h, Character* c)
{
	TTF_Font* font = TTF_OpenFont("font/TerminusTTF-4.39.ttf", 18);
	if(font == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "LOAD FONT ERROR", SDL_GetError(), NULL);
		TTF_Quit();
		SDL_Quit();
		exit(0);
	}
	
	SDL_Color textColor = {255, 255, 255};
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;

	for(int i = 0; i < 6; i++)
	{
		string message;
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
				message = "LCK: " + std::to_string(c->getLuck());
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
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "LOAD SURFACE ERROR", SDL_GetError(), NULL);
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

// Draw the game screen
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
	
	delete mainRect;
}