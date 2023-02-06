#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_ttf.h"
#include <SDL_mixer.h>



class SDL_Handler
{
public:
	SDL_Handler();
	~SDL_Handler();

	bool init();
	void cleanup();
	



	void isgood();

	TTF_Font* font = nullptr;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event event;
};

