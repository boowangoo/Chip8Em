#pragma once

#include <bitset>

#define RESRVD_MEM_START 0x000
#define PROGRM_MEM_START 0x200
#define ETI660_MEM_START 0x600
#define CHIP_8_MEM_SIZE 0x1000

class Chip8Emu_Memory {
public:
  Chip8Emu_Memory();
  ~Chip8Emu_Memory();

  void setBit(uint16_t addr);
  void setBit(uint16_t addr, bool value);
  void clearBit(uint16_t addr);
  bool getBit(uint16_t addr);

  void setBits(uint16_t addr1, uint16_t addr2);
  void setBits(uint16_t addr1, uint16_t addr2, bool value);
  void clearBits(uint16_t addr1, uint16_t addr2);

  void setAllBits();
  void setAllBits(bool value);
  void clearAllBits();
  // getBits(uint16_t addr1, uint16_t addr2);
private:
  std::bitset<CHIP_8_MEM_SIZE> memory;
};