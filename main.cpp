#include <SDL2/SDL.h>
#include <boost/dynamic_bitset>
#include <iostream>
#include <fstream>
#include <string>

#include "PDBP/pdbp.h"

int main(int argc, char **argv) {
  PDBP pdbp;

  std::string fileName;
  std::string fileExt = ".ch8";
  bool correctExt = false;

  if (argc == 2) {
    fileName = argv[1];
    correctExt = fileName.substr(fileName.size() - fileExt.size(), fileExt.size()) == fileExt;
  }
  if (argc != 2 || !correctExt) {
    std::cerr << "bad args" << std::endl;
    return 1;
  }

  std::ifstream file(fileName, std::ios::binary);
  file >> 
    


  pdbp.initDisplay();

  // pdbp.drawPixel(0, 0, 0x40, 0xB0, 0xC0);
  // pdbp.drawPixel(1, 1, 0xFF, 0xFF, 0xFF);
  pdbp.drawRect(2, 3, 4, 4, 0x40, 0xB0, 0xC0);
  // pdbp.drawPixel(2, 1, 0x40, 0xB0, 0xC0);
  pdbp.applyDrawToDisplay();

  // pdbp.setKeyMap(SDLK_UP, [] { std::cout << "Up" << std::endl; });
  // pdbp.setKeyMap(SDLK_DOWN, [] { std::cout << "Down" << std::endl; });
  // pdbp.setKeyMap(SDLK_LEFT, [] { std::cout << "Left" << std::endl; });
  // pdbp.setKeyMap(SDLK_RIGHT, [] { std::cout << "Right" << std::endl; });

  while(!pdbp.pollQuit()) {
    // std::cout << "hi" << std::endl;
  }

  pdbp.exitDisplay(); // tries to delete deallocated pointers
	return 0;
}