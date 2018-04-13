#pragma once

#include <string>
#include <stdint.h>

#define COMPARE_EQUAL

typedef uint16_t adr_t;
typedef uint8_t reg_t;
typedef uint8_t bt4_t;
typedef uint8_t bt8_t;

class Opcodes {
public:
  Opcodes();
  ~Opcodes();
  void parseCode(std::string code);
private:
  void process_op0(std::string code);
  void process_op1(std::string code);
  void process_op2(std::string code);
  void process_op3(std::string code);
  void process_op4(std::string code);
  void process_op5(std::string code);
  void process_op6(std::string code);
  void process_op7(std::string code);
  void process_op8(std::string code);
  void process_op9(std::string code);
  void process_opA(std::string code);
  void process_opB(std::string code);
  void process_opC(std::string code);
  void process_opD(std::string code);
  void process_opE(std::string code);
  void process_opF(std::string code);

  void asn_8xy0(reg_t x, reg_t y);

  void aud_Fx18(reg_t x);

  void bit_8xy1(reg_t x, reg_t y);
  void bit_8xy2(reg_t x, reg_t y);
  void bit_8xy3(reg_t x, reg_t y);
  void bit_8xy6(reg_t x, reg_t y);
  void bit_8xyE(reg_t x, reg_t y);

  void bcd_Fx33(reg_t x);

  void cal_0nnn(adr_t nnn);

  void clk_Fx07(reg_t x);
  void clk_Fx15(reg_t x);

  void cnd_3xkk(reg_t x, bt8_t kk);
  void cnd_4xkk(reg_t x, bt8_t kk);
  void cnd_5xy0(reg_t x, reg_t y);
  void cnd_9xy0(reg_t x, reg_t y);

  void cst_6xkk(reg_t x, bt8_t kk);
  void cst_7xkk(reg_t x, bt8_t kk);

  void dsp_00E0();
  void dsp_Dxyn(reg_t x, reg_t y, bt4_t n);

  void flo_00EE();
  void flo_1nnn(adr_t nnn);
  void flo_2nnn(adr_t nnn);
  void flo_Bnnn(adr_t nnn);

  void key_Ex9E(reg_t x);
  void key_ExA1(reg_t x);
  void key_Fx0A(reg_t x);

  void mat_8xy4(reg_t x, reg_t y);
  void mat_8xy5(reg_t x, reg_t y);
  void mat_8xy7(reg_t x, reg_t y);

  void mem_Annn(adr_t nnn);
  void mem_Fx1E(reg_t x);
  void mem_Fx29(reg_t x);
  void mem_Fx55(reg_t x);
  void mem_Fx65(reg_t x);

  void rnd_Cxkk(reg_t x, bt8_t kk);

};
