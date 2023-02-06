#include "SDL_Handler.h"

SDL_Handler::SDL_Handler() {
    init();
}

SDL_Handler::~SDL_Handler() {
    cleanup();
}

void SDL_Handler::isgood() {
    std::cout << "All good" << std::endl;
}


bool SDL_Handler::init() {
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Couldn't initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    if (IMG_Init(IMG_INIT_PNG) < 0) {
        std::cout << "Couldn't initialize SDL IMG: " << IMG_GetError() << std::endl;
        return false;
    }

    if (IMG_Init(IMG_INIT_JPG) < 0) {
        std::cout << "Couldn't initialize SDL IMG: " << IMG_GetError() << std::endl;
        return false;
    }

    if (SDL_CreateWindowAndRenderer(1800, 1000, NULL, &window, &renderer)) {
        std::cout << "Couldn't create window and renderer: " << SDL_GetError() << std::endl;
        return false;
    }

    if (TTF_Init() == -1) {
        std::cout << "Couldn't init TTF: " << TTF_GetError() << std::endl;
        return false;
    }

    font = TTF_OpenFont("Assets/Fonts/Roboto.ttf", 48);
    if (!font) {
        std::cout << "Couldn't init font: " << TTF_GetError() << std::endl;
        return false;
    }

    return true;
}





void SDL_Handler::cleanup() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_CloseFont(font);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}
