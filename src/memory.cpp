#include "../lib/memory.h"

Chip8Emu_Memory::Chip8Emu_Memory() {
  memory.reset();
}
Chip8Emu_Memory::~Chip8Emu_Memory() {
  memory.reset();
}

void Chip8Emu_Memory::setBit(uint16_t addr) {
  memory.set(addr, true);
}

void Chip8Emu_Memory::setBit(uint16_t addr, bool value) {
  memory.set(addr, value);
}

void Chip8Emu_Memory::clearBit(uint16_t addr) {
  setBit(addr, false);
}

bool Chip8Emu_Memory::getBit(uint16_t addr) {
  return (bool) memory[addr];
}

void Chip8Emu_Memory::setBits(uint16_t addr1, uint16_t addr2) {
  setBits(addr1, addr2, true);
}

void Chip8Emu_Memory::setBits(uint16_t addr1, uint16_t addr2, bool value) {
  for (int i = addr1, i <= addr2; i++) {
    setBit(i, value);
  }
}

void Chip8Emu_Memory::clearBits(uint16_t addr1, uint16_t addr2) {
  setBits(addr1, addr2, false);
}

void Chip8Emu_Memory::setAllBits() {
  memory.set();
}

void Chip8Emu_Memory::setAllBits(bool value) {
  setBits(0x00, CHIP_8_MEM_SIZE -1, value);
}

void Chip8Emu_Memory::clearAllBits() {
  memory.reset();
}

// Chip8Emu_Memory::getBits(uint16_t addr1, uint16_t addr2) {
// }