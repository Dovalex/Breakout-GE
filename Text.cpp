#include "Text.h"


Text::Text(SDL_Handler* handler, TextureAtlas& textureAtlas, SDL_Rect position, std::initializer_list<std::string> words) : listOfTexts(words) {
	Entity::position = position;
	
	for (int i = 0; i < listOfTexts.size(); i++)
	{
		textureAtlas.addToAtlas(handler, listOfTexts[i], textureEnum::Word, listOfTexts[i]);
	}
	Entity::sourceRect = textureAtlas.mapOfRects[listOfTexts[0]];
}


