#pragma once
#include "Entity.h"
#include <vector>
#include "TextureAtlas.h"
#include <initializer_list>


class Text : public Entity
{
public:
	std::vector<std::string> listOfTexts;
	int currentResolution = 0;
	Text(SDL_Handler* handler, TextureAtlas& textureAtlas, SDL_Rect position, std::initializer_list<std::string> words);
};

