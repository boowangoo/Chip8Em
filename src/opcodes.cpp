#include "../lib/opcodes.h"

void Opcodes::parseCode(std::string code) {
  if (code.length != 4) {
    // throw a "not a code" error
  }
  switch(code[0]) {
  case '0':
    process_op0(code);
    break;
  case '1':
    process_op1(code);
    break;
  case '2':
    process_op2(code);
    break;
  case '3':
    process_op3(code);
    break;
  case '4':
    process_op4(code);
    break;
  case '5':
    process_op5(code);
    break;
  case '6':
    process_op6(code);
    break;
  case '7':
    process_op7(code);
    break;
  case '8':
    process_op8(code);
    break;
  case '9':
    process_op9(code);
    break;
  case 'A':
    process_opA(code);
    break;
  case 'B':
    process_opB(code);
    break;
  case 'C':
    process_opC(code);
    break;
  case 'D':
    process_opD(code);
    break;
  case 'E':
    process_opE(code);
    break;
  case 'F':
    process_opF(code);
    break;
  default:
    // not a code
    break;
  }
}

adr_t get_nnn(std::string code) {
  return (adr_t) std::stoul(code.substr(0, 3), 0, 16);
}

void Opcodes::process_op0(std::string code) {
  if (code == "0E00")
    dsp_00E0();
  else if (code == "00EE")
    flo_00EE();
  else {
    cal_0nnn(get_nnn(code));
  }
}

void Opcodes::process_op1(std::string code) {
  flo_1nnn(get_nnn(code));
}

void Opcodes::process_op2(std::string code) {
  flo_2nnn(get_nnn(code));
}

void Opcodes::process_op3(std::string code) {
  cnd_3xkk(get_x(code), get_kk(code));
}

void Opcodes::process_op4(std::string code) {
  cnd_4xkk(get_x(code), get_kk(code));
}

void Opcodes::process_op5(std::string code) {
  cnd_5xy0(get_x(code), get_y(code));
}

void Opcodes::process_op6(std::string code) {
  cst_6xkk(get_x(code), get_kk(code));
}

void Opcodes::process_op7(std::string code) {
  cst_7xkk(get_x(code), get_kk(code));
}

void Opcodes::process_op8(std::string code) {
  switch(code[3]) {
  case '0':
    break;
  case '1':
    break;
  case '2':
    break;
  case '3':
    break;
  case '4':
    break;
  case '5':
    break;
  case '6':
    break;
  case '7':
    break;
  case 'E':
    break;
  default:

    break;
  }
}

void Opcodes::process_op9(std::string code) {

}

void Opcodes::process_opA(std::string code) {

}

void Opcodes::process_opB(std::string code) {

}

void Opcodes::process_opC(std::string code) {

}

void Opcodes::process_opD(std::string code) {

}

void Opcodes::process_opE(std::string code) {

}

void Opcodes::process_opF(std::string code) {

}
