#include <iostream>
#include <functional>

#include "../lib/opcodes.h"

adr_t get_nnn(std::string code) {
  return (adr_t) std::stoul(code.substr(1, 3), 0, 16);
}

bt8_t get_kk(std::string code) {
  return (bt8_t) std::stoul(code.substr(2, 2), 0, 16);
}

bt4_t get_n(std::string code) {
  return (bt4_t) std::stoul(code.substr(3, 1), 0, 16);
}

reg_t get_x(std::string code) {
  return (reg_t) std::stoul(code.substr(1, 1), 0, 16);
}

reg_t get_y(std::string code) {
  return (reg_t) std::stoul(code.substr(2, 1), 0, 16);
}

void Opcodes::parseCode(std::string code) {
  if (code.length() != 4) {
    return;
    // throw a "not a code" error
  }
  switch(code[0]) {
  case '0':
    process_op0(code);
    break;
  case '1':
    // std::cout << "1nnn" << std::endl;
    // std::cout << "nnn:\t" << get_nnn(code) << std::endl;
    // flo_1nnn(get_nnn(code));
    return FLO_1NNN;
  case '2':
    // std::cout << "2nnn" << std::endl;
    // std::cout << "nnn:\t" << get_nnn(code) << std::endl;
    // flo_2nnn(get_nnn(code));
    return FLO_2NNN;
  case '3':
    // std::cout << "3xkk" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "kk:\t" << (int) get_kk(code) << std::endl;
    // cnd_3xkk(get_x(code), get_kk(code));
    return CND_3XKK;
  case '4':
    // std::cout << "4xkk" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "kk:\t" << (int) get_kk(code) << std::endl;
    // cnd_4xkk(get_x(code), get_kk(code));
    return CND_4XKK;
  case '5':
    process_op5(code);
    break;
  case '6':
    // std::cout << "6xkk" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "kk:\t" << (int) get_kk(code) << std::endl;
    // cst_6xkk(get_x(code), get_kk(code));
    return CST_6XKK;
  case '7':
    // std::cout << "7xkk" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "kk:\t" << (int) get_kk(code) << std::endl;
    // cst_7xkk(get_x(code), get_kk(code));
    return CST_7XKK;
  case '8':
    process_op8(code);
    break;
  case '9':
    process_op9(code);
    break;
  case 'a':
    // std::cout << "Annn" << std::endl;
    // std::cout << "nnn:\t" << get_nnn(code) << std::endl;
    return MEM_ANNN;
  case 'b':
    std::cout << "Bnnn" << std::endl;
    std::cout << "nnn:\t" << get_nnn(code) << std::endl;
    return FLO_BNNN;
  case 'c':
    // std::cout << "Cxkk" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "kk:\t" << (int) get_kk(code) << std::endl;
    return RND_CXKK;
  case 'd':
    // std::cout << "Dxyn" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "y:\t" << (int) get_y(code) << std::endl;
    // std::cout << "n:\t" << (int) get_n(code) << std::endl;
    return DSP_DXYN;
  case 'e':
    process_opE(code);
    break;
  case 'f':
    process_opF(code);
    break;
  default:
    // not a code
    std::cout << "NOT A FUCKING INSTRUCTION" << std::endl;
    break;
  }
}

void Opcodes::process_op0(std::string code) {
  if (code == "0E00")
    // std::cout << "0E00" << std::endl;
    // dsp_00E0();
    return DSP_00E0;
  else if (code == "00EE")
    // std::cout << "00EE" << std::endl;
    // flo_00EE();
    return FLO_00EE;
  else {
    // std::cout << "0nnn" << std::endl;
    // std::cout << "nnn:\t" << get_nnn(code) << std::endl;
    // cal_0nnn(get_nnn(code));
    return CAL_0NNN;
  }
}

void Opcodes::process_op5(std::string code) {
  if (code[3] == '0')
    // std::cout << "5xy0" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "y:\t" << (int) get_y(code) << std::endl;
    // cnd_5xy0(get_x(code), get_y(code));
    return CND_5XY0;
}

void Opcodes::process_op8(std::string code) {
  switch(code[3]) {
  case '0':
    // std::cout << "8xy0" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "y:\t" << (int) get_y(code) << std::endl;
    return ASN_8XY0;
  case '1':
    // std::cout << "8xy1" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "y:\t" << (int) get_y(code) << std::endl;
    return BIT_8XY1;
  case '2':
    // std::cout << "8xy2" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "y:\t" << (int) get_y(code) << std::endl;
    return BIT_8XY2;
  case '3':
    // std::cout << "8xy3" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "y:\t" << (int) get_y(code) << std::endl;
    return BIT_8XY3;
  case '4':
    // std::cout << "8xy4" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "y:\t" << (int) get_y(code) << std::endl;
    return MAT_8XY4;
  case '5':
    // std::cout << "8xy5" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "y:\t" << (int) get_y(code) << std::endl;
    return MAT_8XY5;
  case '6':
    // std::cout << "8xy6" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "y:\t" << (int) get_y(code) << std::endl;
    return BIT_8XY6;
  case '7':
    // std::cout << "8xy7" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "y:\t" << (int) get_y(code) << std::endl;
    return MAT_8XY7;
  case 'e':
    // std::cout << "8xye" << std::endl;
    // std::cout << "x:\t" << (int) get_x(code) << std::endl;
    // std::cout << "y:\t" << (int) get_y(code) << std::endl;
    return BIT_8XYE;
  default:
    std::cout << "NOT A FUCKING INSTRUCTION" << std::endl;
    break;
  }
}

void Opcodes::process_op9(std::string code) {
  if (code[3] == '0')
    std::cout << "9xy0" << std::endl;
    std::cout << "x:\t" << (int) get_x(code) << std::endl;
    std::cout << "y:\t" << (int) get_y(code) << std::endl;
    return CND_9XY0;
}

void Opcodes::process_opE(std::string code) {
  if (code[2] == '9' && code[3] == 'e') {
    std::cout << "Ex9E" << std::endl;
    std::cout << "x:\t" << (int) get_x(code) << std::endl;
    return KEY_EX9E;
  }
  else if (code[2] == 'a' && code[3] == '1') {
    std::cout << "ExA1" << std::endl;
    std::cout << "x:\t" << (int) get_x(code) << std::endl;
    return KEY_EXA1;
  }
}

void Opcodes::process_opF(std::string code) {
  if (code[2] == '0' && code[3] == '7') {
    std::cout << "Fx07" << std::endl;
    std::cout << "x:\t" << (int) get_x(code) << std::endl;
    return CLK_FX07;
  }
  else if (code[2] == '0' && code[3] == 'a') {
    std::cout << "Fx0A" << std::endl;
    std::cout << "x:\t" << (int) get_x(code) << std::endl;
    return KEY_FX0A;
  }
  else if (code[2] == '1' && code[3] == '5') {
    std::cout << "Fx15" << std::endl;
    std::cout << "x:\t" << (int) get_x(code) << std::endl;
    return CLK_FX15;
  }
  else if (code[2] == '1' && code[3] == '8') {
    std::cout << "Fx18" << std::endl;
    std::cout << "x:\t" << (int) get_x(code) << std::endl;
    return AUD_FX18;
  }
  else if (code[2] == '1' && code[3] == 'e') {
    std::cout << "Fx1E" << std::endl;
    std::cout << "x:\t" << (int) get_x(code) << std::endl;
    return MEM_FX1E;
  }
  else if (code[2] == '2' && code[3] == '9') {
    std::cout << "Fx29" << std::endl;
    std::cout << "x:\t" << (int) get_x(code) << std::endl;
    return MEM_FX29;
  }
  else if (code[2] == '3' && code[3] == '3') {
    std::cout << "Fx33" << std::endl;
    std::cout << "x:\t" << (int) get_x(code) << std::endl;
    return BCD_FX33;
  }
  else if (code[2] == '5' && code[3] == '5') {
    std::cout << "Fx55" << std::endl;
    std::cout << "x:\t" << (int) get_x(code) << std::endl;
    return MEM_FX55;
  }
  else if (code[2] == '6' && code[3] == '5') {
    std::cout << "Fx65" << std::endl;
    std::cout << "x:\t" << (int) get_x(code) << std::endl;
    return MEM_FX65;
  }
  else
    std::cout << "NOT A FUCKING INSTRUCTION" << std::endl;
}
