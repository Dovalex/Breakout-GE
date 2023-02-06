#include "Entity.h"

Entity::Entity(SDL_Rect sRect, SDL_Rect position) : sourceRect(sRect), position(position){};

Entity::Entity() {};
void Entity::drawToScreen(SDL_Handler* handler, TextureAtlas& textureAtlas) {
	SDL_RenderCopy(handler->renderer, textureAtlas.getTexture(), &sourceRect, &position);
}