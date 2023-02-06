#pragma once
#include "SDL_Handler.h"
#include "TextureAtlas.h"
#include "Button.h"



class App
{
public:


	App();
	SDL_Handler handler;


	void programLoop();
	int startMenu();
	int optionsMenu();
private:

};

