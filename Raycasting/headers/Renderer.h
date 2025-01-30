#pragma once
#include "SDL2/SDL.h"
#include "iostream"
#include <vector>
#include <math.h>


class Renderer {
public:
	void createWindow(const char* title, int width, int height);
	void update();
	bool isRunning() { return isrunning; };
	void drawRectangleMap(int x, int y, int width, int heigth, SDL_Color color, std::vector<std::vector<int>> map);
	void drawFirsperson(int x, int y, int width, int heigth, SDL_Color color);
	void clear();
	void present();
	void close();
	void renderPositionTop(int width, int height);
	SDL_Rect returnPosition() { return position; };
	void DrawLaser(SDL_Rect Position, std::vector<std::vector<int>> map);
	bool wallCheck(SDL_Rect position, std::vector<std::vector<int>> map, float angle);

private:
	SDL_Rect laser;
	float angle{ 0.0f };
	SDL_Rect position;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool isrunning = false;
	std::vector<std::vector<int>> mapaux;
};

