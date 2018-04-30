#include <SDL2/SDL.h>
#include <iostream>

#include "PDBP/pdbp.h"

int main() {

  PDBP pdbp;

  pdbp.initDisplay();

  // pdbp.drawPixel(0, 0, 0x40, 0xB0, 0xC0);
  // pdbp.drawPixel(1, 1, 0xFF, 0xFF, 0xFF);
  pdbp.drawRect(2, 3, 4, 4, 0x40, 0xB0, 0xC0);
  // pdbp.drawPixel(2, 1, 0x40, 0xB0, 0xC0);
  pdbp.applyDrawToDisplay();

  pdbp.setKeyMap(SDLK_UP, [] { std::cout << "Up" << std::endl; });
  pdbp.setKeyMap(SDLK_DOWN, [] { std::cout << "Down" << std::endl; });
  pdbp.setKeyMap(SDLK_LEFT, [] { std::cout << "Left" << std::endl; });
  pdbp.setKeyMap(SDLK_RIGHT, [] { std::cout << "Right" << std::endl; });

  while(pdbp.polls()) {
  }

  // pdbp.exitDisplay(); // tries to delete deallocated pointers
	return 0;
}