#include <SDL2/SDL.h>

#include "PDBP/pdbp.h"

int main() {

  PDBP* pdbp = new PDBP();

  pdbp->initDisplay();

  // pdbp->drawPixel(0, 0, 0x40, 0xB0, 0xC0);
  // pdbp->drawPixel(1, 1, 0xFF, 0xFF, 0xFF);
  pdbp->drawRect(2, 3, 4, 4, 0x40, 0xB0, 0xC0);
  // pdbp->drawPixel(2, 1, 0x40, 0xB0, 0xC0);
  pdbp->applyDrawToDisplay();

  bool running = true;
  while(running) {
    SDL_Event e;
  	SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) {
      running = false;
    }
  }

  pdbp->exitDisplay();
	return 0;
}