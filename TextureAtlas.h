#pragma once
#include<SDL.h>
#include<string>
#include<vector>
#include<unordered_map>
#include "SDL_Handler.h"

struct Dimensions
{
	SDL_Rect charDimensions{ 0,0,48,48 };
	SDL_Rect brickDimensions{ 0,0,128,32 };
	SDL_Rect ballDimensions{ 0,0,32,32 };
	SDL_Rect arrowDimensions{ 0,0,32,32 };
	SDL_Rect boxDimensions{ 0,0,32,32 };
};



enum class textureEnum {
	Word,
	Brick,
	Ball,
	Arrow,
	Box,
	Checkmark
};

class TextureAtlas
{
public:

	void addToAtlas(SDL_Handler* handler, std::string const& wordToAdd, textureEnum typeOfTexture, std::string name);
	SDL_Texture* getTexture();

	TextureAtlas(SDL_Handler* handler);
	~TextureAtlas();


	std::unordered_map<std::string, SDL_Rect> mapOfRects;
	std::vector<SDL_Rect> sourceRects;
private:
	SDL_Texture* textureAtlas;


	int thingID;
	//atlas position calculation
	int currentTextureX = 0;
	int currentTextureY = 0;
	int currentLargestY = 0;
	int MAX_WIDTH = 2048;
	int MAX_HEIGHT = 2048;
};



