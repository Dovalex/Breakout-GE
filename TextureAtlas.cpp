#include "TextureAtlas.h"
#include "tinyxml2.h"
 
//creating standardized texture atlas with fixed size
TextureAtlas::TextureAtlas(SDL_Handler* handler) {
	//setting uo the texture atlas so that it can be a render targer
	textureAtlas = SDL_CreateTexture(handler->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, MAX_WIDTH, MAX_HEIGHT);
}

TextureAtlas::~TextureAtlas() {
	//cleanup
	SDL_DestroyTexture(textureAtlas);
	textureAtlas = nullptr;
}


void TextureAtlas::addToAtlas(SDL_Handler* handler, std::string const& thingToAdd, textureEnum typeOfTexture, std::string name) {
	SDL_Color color = { 255,255,255 };
	Dimensions dimensions;
	SDL_Surface* tempSurface = nullptr;
	SDL_Texture* tempTexture = nullptr;
	SDL_Rect drawingRect;

	
	//set renderer to render to the texture atlas instead to the window
	SDL_SetRenderTarget(handler->renderer, textureAtlas);
	
	
	drawingRect.x = currentTextureX;
	drawingRect.y = currentTextureY;

	//settung up a drawing rectangle for the specific texture
	if (typeOfTexture == textureEnum::Word)
	{
		drawingRect.w = dimensions.charDimensions.w * thingToAdd.length();
		drawingRect.h = dimensions.charDimensions.h;
	}

	else if (typeOfTexture == textureEnum::Brick)
	{
		drawingRect.w = dimensions.brickDimensions.w;
		drawingRect.h = dimensions.brickDimensions.h;
	}

	else if (typeOfTexture == textureEnum::Ball)
	{
		drawingRect.w = dimensions.ballDimensions.w;
		drawingRect.h = dimensions.ballDimensions.h;
	}

	else if (typeOfTexture == textureEnum::Arrow)
	{
		drawingRect.w = dimensions.arrowDimensions.w;
		drawingRect.h = dimensions.arrowDimensions.h;
	}

	else if (typeOfTexture == textureEnum::Box)
	{
		drawingRect.w = dimensions.boxDimensions.w;
		drawingRect.h = dimensions.boxDimensions.h;
	}

	//keeping track of the largest y in case new row is needed
	if (currentLargestY < drawingRect.y + drawingRect.h)
	{
		currentLargestY = drawingRect.y + drawingRect.h;
	}


	//using a new row of textures in case the row is filled
	if (drawingRect.x + drawingRect.w >= MAX_WIDTH)
	{
		drawingRect.x = 0;
		currentTextureX = 0;
		drawingRect.y = currentLargestY;
		currentTextureY = currentLargestY;
	}

	//adding a word to the texture atlas
	if (typeOfTexture == textureEnum::Word)
	{
		if (!(tempSurface = TTF_RenderText_Blended(handler->font, thingToAdd.c_str(), color))) {
			std::cout << "Error loading text : " << TTF_GetError() << std::endl;
		}
		else
		{
			tempTexture = SDL_CreateTextureFromSurface(handler->renderer, tempSurface);
			SDL_RenderCopy(handler->renderer, tempTexture, NULL, &drawingRect);
		}
	}

	//adding an image to the texture atlas
	if (typeOfTexture == textureEnum::Brick || typeOfTexture == textureEnum::Ball)
	{
		tempSurface = IMG_Load(thingToAdd.c_str());

		if (!tempSurface) {
			std::cout << "Error loading image " << IMG_GetError() << std::endl;
		}
		else
		{
			tempTexture = SDL_CreateTextureFromSurface(handler->renderer, tempSurface);
			SDL_RenderCopy(handler->renderer, tempTexture, NULL, &drawingRect);
		}
	}

	if (typeOfTexture == textureEnum::Arrow)
	{
		tempSurface = IMG_Load(thingToAdd.c_str());

		if (!tempSurface) {
			std::cout << "Error loading image " << IMG_GetError() << std::endl;
		}
		else
		{
			tempTexture = SDL_CreateTextureFromSurface(handler->renderer, tempSurface);
			SDL_RenderCopy(handler->renderer, tempTexture, NULL, &drawingRect);
			mapOfRects[name] = drawingRect;
			currentTextureX += drawingRect.w;
			SDL_RenderCopyEx(handler->renderer, tempTexture, NULL, &drawingRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
			name.append("_flipped");
		}
	}
	if (typeOfTexture == textureEnum::Box)
	{
		tempSurface = IMG_Load(thingToAdd.c_str());

		if (!tempSurface) {
			std::cout << "Error loading image " << IMG_GetError() << std::endl;
		}
		else
		{
			tempTexture = SDL_CreateTextureFromSurface(handler->renderer, tempSurface);
			SDL_RenderCopy(handler->renderer, tempTexture, NULL, &drawingRect);



			//add checkmark for the box
			// 
			//mapOfRects[name] = drawingRect;
			//currentTextureX += drawingRect.w;
			// 
			//tempSurface = IMG_Load(thingToAdd.c_str());
			//if (!tempSurface) {
			//	std::cout << "Error loading image " << IMG_GetError() << std::endl;
			//}
			//else
			//{
			//	tempTexture = SDL_CreateTextureFromSurface(handler->renderer, tempSurface);
			//	SDL_RenderCopy(handler->renderer, tempTexture, NULL, &drawingRect);
			//	name.append("_flipped");
			//}
		}
	}
	
	currentTextureX += drawingRect.w;

	//saving the rect in the map under the specified name
	mapOfRects[name] = drawingRect;

	//reset the render target to the window
	SDL_SetRenderTarget(handler->renderer, NULL);

	//cleanup
	SDL_FreeSurface(tempSurface);
	SDL_DestroyTexture(tempTexture);
	tempSurface = nullptr;
	tempTexture = nullptr;
}






SDL_Texture* TextureAtlas::getTexture() {
	return textureAtlas;
}