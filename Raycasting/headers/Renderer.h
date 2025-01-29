#pragma once
#include "SDL2/SDL.h"
#include "iostream"
#include <vector>

class Renderer {
public:
	void createWindow(const char* title, int width, int height);
	void update();
	bool isRunning() { return isrunning; };
	void drawRectangle(int x, int y, int width, int heigth, SDL_Color color, std::vector<std::vector<int>> map);
	void clear();
	void present();
	void close();
	void renderPosition(int width, int height);
	SDL_Rect returnPosition() { return position; };
	void DrawLaser(SDL_Rect Position);
private:
	SDL_Rect laser;
	float angle{ 0.0f };
	SDL_Rect position;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool isrunning = false;
};