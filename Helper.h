#pragma once
#include <SDL.h>
#include <vector>
#include "SDL_Handler.h"
#include "tinyxml2.h"

namespace helper {


	//dynamically makes a grid based on provided renderer size, number of cells, spacing and offset
	//makes a 1d vector simulating 2d behaviour with 2 for loops
	std::vector<SDL_Rect> grid(SDL_Handler* handler, const int& rows, const int& columns, const float& xOffset, const float& yOffset, const float& minXOffset, const float& minYOffset, const int& rowSpacing, const int& columnSpacing) {
		int screenWidht, screenHeight, widthUnit, heightUnit, availableScreenWidth, availableScreenHeight;
		SDL_GetRendererOutputSize(handler->renderer, &screenWidht, &screenHeight);
		std::vector<SDL_Rect> newGrid;
		availableScreenWidth = screenWidht - (screenWidht * xOffset) - (screenWidht * minXOffset);
		availableScreenHeight = screenHeight - (screenHeight * yOffset) - (screenHeight * minYOffset);

		widthUnit = (availableScreenWidth - ((columns - 1) * columnSpacing)) / columns;
		heightUnit = (availableScreenHeight - ((rows - 1) * rowSpacing)) / rows;

		newGrid.reserve(rows * columns);

		SDL_Rect tempRect, startRect;

		//loss of data is maximum one pixel
		//acceptable loss in favour of gaining offset precision
		startRect.x = (screenWidht * xOffset);
		startRect.y = (screenHeight * yOffset);
		startRect.w = widthUnit;
		startRect.h = heightUnit;

		tempRect = startRect;

		for (int i = 0; i < rows; i++)
		{
			tempRect.x = startRect.x;
			tempRect.y = startRect.y + (i * (heightUnit + rowSpacing));
			for (int j = 0; j < columns; j++)
			{
				tempRect.x = startRect.x + (j * (widthUnit + columnSpacing));
				newGrid.push_back(tempRect);
			}

		}
		return newGrid;
	}

    //a recursive function that returns requested element
    template <class T>
    tinyxml2::XMLElement* getElement(tinyxml2::XMLElement* element, T elementName) {
        element = element->FirstChildElement(elementName);
        if (element != NULL)
        {
            return element;
        }
        else
        {
            std::cout << "no such element!" << std::endl;
        }
    }

    template <class T, class ...T2>
    tinyxml2::XMLElement* getElement(tinyxml2::XMLElement* element, T elementName, T2... restOfElements) {
        element = element->FirstChildElement(elementName);
        if (element != NULL)
        {
            element = getElement(element, restOfElements...);
            return element;
        }
        else
        {
            std::cout << "no such element!" << std::endl;
        }
    }


    //loads or resets to the first element in the file
    tinyxml2::XMLElement* resetElement(tinyxml2::XMLDocument& XML_doc) {
        tinyxml2::XMLElement* element = XML_doc.FirstChildElement();
        return element;
    }



    //function for getting the next sibling element
    tinyxml2::XMLElement* nextSibling(tinyxml2::XMLElement* element) {
        element = element->NextSiblingElement();
        return element;
    }




}