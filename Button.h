#pragma once
#include <SDL.h>
#include "Entity.h"


class Button : public Entity
{
public:
	Button(SDL_Rect sRect, SDL_Rect position);

	bool isMouseOvered(const int& x, const int& y);
};

