#include "App.h"
#include "Helper.h"
#include "Text.h"




App::App() {
	programLoop();
}

void App::programLoop() {
	int choice = 1;
	bool running = true;
	while (choice != 0)
	{
		if (choice == 1)
		{
			choice = startMenu();
		}
		if (choice == 2)
		{

		}
		if (choice == 3)
		{
			choice = optionsMenu();
		}
	}

}



int App::startMenu() {
	TextureAtlas textureAtlas(&handler);

	std::vector<SDL_Rect> menuGrid = helper::grid(&handler, 3, 1, 0.3f, 0.1f, 0.3f, 0.1f, 50, 50);

	textureAtlas.addToAtlas(&handler, "Start Game", textureEnum::Word, "startGame");
	Button startGameButton(textureAtlas.mapOfRects.at("startGame"), menuGrid[0]);
	textureAtlas.addToAtlas(&handler, "Options", textureEnum::Word, "options");
	Button optionsButton(textureAtlas.mapOfRects.at("options"), menuGrid[1]);
	textureAtlas.addToAtlas(&handler, "Exit", textureEnum::Word, "exit");
	Button exitButton(textureAtlas.mapOfRects.at("exit"), menuGrid[2]);

	std::cout << "Button " << sizeof(Button) << " bytes" << std::endl;
	std::cout << "Button pointer: " << sizeof(Button*) << " bytes" << std::endl;

	SDL_Event event;
	int mousePosX, mousePosY;
	while (true)
	{
		SDL_RenderClear(handler.renderer);
		SDL_PollEvent(&event);
		SDL_GetMouseState(&mousePosX, &mousePosY);
		

		startGameButton.drawToScreen(&handler, textureAtlas);
		optionsButton.drawToScreen(&handler, textureAtlas);
		exitButton.drawToScreen(&handler, textureAtlas);

		if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		{
			return 0;
		}

		if (startGameButton.isMouseOvered(mousePosX, mousePosY)) {
			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			{
				return 2;
			std::cout << "clicked start" << std::endl;
			}
		}

		if (optionsButton.isMouseOvered(mousePosX, mousePosY)) {
			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			{
				return 3;
				std::cout << "clicked options" << std::endl;
			}
		}

		if (exitButton.isMouseOvered(mousePosX, mousePosY)) {
			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			{
				return 0;
			}
		}
		SDL_RenderPresent(handler.renderer);

	}
}

int App::optionsMenu() {

	std::vector<SDL_Rect> menuGrid = helper::grid(&handler, 3, 3, 0.3f, 0.1f, 0.3f, 0.1f, 50, 50);
	TextureAtlas textureAtlas(&handler);
	SDL_Event event;
	int mousePosX, mousePosY;





	Text resolutions(&handler, textureAtlas, menuGrid[0], { "600x400", "1280x720", "1920x1080" });




	while (true)
	{
		SDL_RenderClear(handler.renderer);
		SDL_PollEvent(&event);
		SDL_GetMouseState(&mousePosX, &mousePosY);

		resolutions.drawToScreen(&handler, textureAtlas);
		if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		{
			return 0;
		}






		SDL_RenderPresent(handler.renderer);

	}
	//Button startGameButton(textureAtlas.sourceRects[0], menuGrid[1]);
	//textureAtlas.addToAtlas(&handler, "Fulscreen", textureEnum::Word, "Fullscreen");
	//Button startGameButton(textureAtlas.sourceRects[0], menuGrid[1]);
	//textureAtlas.addToAtlas(&handler, "1200x900", textureEnum::Word, "1200x900");
	//Button startGameButton(textureAtlas.sourceRects[0], menuGrid[1]);
	//textureAtlas.addToAtlas(&handler, "Options", textureEnum::Word);
	//Button optionsButton(textureAtlas.sourceRects[1], menuGrid[4]);
	//textureAtlas.addToAtlas(&handler, "Exit", textureEnum::Word);
	//Button exitButton(textureAtlas.sourceRects[2], menuGrid[7]);

	std::cout << "success" << std::endl;
	return 0;
}