#include "Button.h"

Button::Button(SDL_Rect sRect, SDL_Rect position) : Entity(sRect, position) {}

bool Button::isMouseOvered(const int& x, const int& y) {
	if (x > position.x && x < position.x + position.w && y > position.y && y < position.y + position.h)
	{		
		return true;
	}
	else
	{
		return false;
	}
}

