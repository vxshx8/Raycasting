#include <SDL2/SDL.h>
#include "../headers/Renderer.h"
#include <memory>

int main(int argc, char* argv[]) {
	std::shared_ptr<Renderer> raycaster = std::make_shared<Renderer>();
	raycaster->createWindow("Raycaster", 1600, 800);
	raycaster->clear();

	while (raycaster->isRunning()) {
		raycaster->drawRectangle(0, 0,800, 800, { 12,23,0,255 });
		raycaster->present();
		raycaster->update();
	}
	raycaster->close();

	return 0;
}
