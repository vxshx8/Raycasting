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

void Renderer::renderPosition(int width,int height) {
	int midleMap = width / 2;
	int midle = midleMap / 2;
	int midleheight = height / 2;
	position={midle,midleheight,20,20 };
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(renderer, &position);
}

void Renderer::drawRectangle(int x, int y, int width, int heigth, SDL_Color color, std::vector<std::vector<int>> map) {
	SDL_Rect rect{ x,y,width,heigth };
	const int gridSize = 80; 
	SDL_Rect drawWalls{ x,y,80,80 };
	
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j <10;j ++) {
			if (map[i][j] == 1) {
				SDL_SetRenderDrawColor(renderer, 255,0,0,255);
				SDL_RenderFillRect(renderer, &drawWalls);
			}
			drawWalls.x += gridSize;
		}
		drawWalls.x = x;
		drawWalls.y += gridSize;
	}

	SDL_SetRenderDrawColor(renderer,color.r,color.b,color.g,color.a);
	for (int y = 0; y <= 800; y += gridSize) {
		SDL_RenderDrawLine(renderer, 0, y, 800, y);
	}

	
	for (int x = 0; x <= 800; x += gridSize) {
		SDL_RenderDrawLine(renderer, x, 0, x, 800); 
	}
}

void Renderer::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			isrunning = false;
		}
		if (event.key.keysym.sym == SDLK_w) {
			position.x += 5;
			break;
		}
	}
	SDL_RenderFillRect(renderer, &position);

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

void Renderer::DrawLaser(SDL_Rect Position) {
	SDL_RenderDrawLine(renderer, Position.x, position.y, 800, 800);
}