#include "../headers/Renderer.h"

void Renderer::createWindow(const char* title, int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Cannot init SDL correctly " << SDL_GetError() << "\n";
		isrunning = false;
		return;
 	}
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (!window) {
		std::cout << "Cannot create SDL window " << SDL_GetError() << "\n";
		isrunning = false;
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		std::cout << "Cannot create Renderer " << SDL_GetError() << "\n";
		isrunning = false;
		return;
	}

	isrunning = true;
}

void Renderer::drawRectangle(int x, int y, int width, int heigth, SDL_Color color) {
	SDL_SetRenderDrawColor(renderer,color.r,color.b,color.g,color.a);
	SDL_Rect rect{ x,y,width,heigth };
	SDL_RenderFillRect(renderer, &rect);
}

void Renderer::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			isrunning = false;
		}
	}
}

void Renderer::clear() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Renderer::present() {
	SDL_RenderPresent(renderer);
}

void Renderer::close() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}