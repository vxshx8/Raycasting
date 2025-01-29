#include <SDL2/SDL.h>
#include "../headers/Renderer.h"
#include <memory>
#include "vector"

std::vector<std::vector<int>> map = {
	   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	   {1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
	   {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	   {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
	   {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	   {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
	   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	   {1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
	   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int main(int argc, char* argv[]) {
	std::shared_ptr<Renderer> raycaster = std::make_shared<Renderer>();
	raycaster->createWindow("Raycaster", 1600, 800);
	raycaster->renderPosition(1600,800);

	while (raycaster->isRunning()) {
		raycaster->clear();
		raycaster->drawRectangle(0, 0,800, 800, { 255,255,255,255 },map);
		
		raycaster->update();
		raycaster->DrawLaser(raycaster->returnPosition(),map);
		raycaster->present();
	}
	raycaster->close();

	return 0;
}
