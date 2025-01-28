#pragma once
#include "SDL2/SDL.h"
#include "iostream"


class Renderer {
public:
	void createWindow(const char* title, int width, int height);
	void update();
	bool isRunning() { return isrunning; };
	void drawRectangle(int x, int y, int width, int heigth, SDL_Color color);
	void clear();
	void present();
	void close();
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool isrunning = false;
};