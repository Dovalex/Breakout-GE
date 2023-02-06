#pragma once
#include <SDL.h>
#include "TextureAtlas.h"
#include <memory>


class Entity
{
public:
	Entity(SDL_Rect sRect, SDL_Rect position);
	Entity();
	void drawToScreen(SDL_Handler* handler, TextureAtlas& textureAtlas);


	//source rect in texture atlas
	SDL_Rect sourceRect;
	//position on screen
	SDL_Rect position;
};

