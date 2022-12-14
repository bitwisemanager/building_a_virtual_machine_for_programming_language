/**
 * Instruction set for Eva VM
 */

#ifndef OP_CODE__H
#define OP_CODE__H

#include <stdint.h>
#include <string>

#include "../vm/eva_value.h"

/**
 * Stops the program
 */
#define OP_HALT 0x00

/**
 * Pushes a const into the stack
 */
#define OP_CONST 0x01

/**
 * Math instruction
 */
#define OP_ADD 0x02
#define OP_SUB 0x03
#define OP_MUL 0x04
#define OP_DIV 0x05

/**
 * Comparison
 */
#define OP_COMPARE 0x06

/**
 * Control flow: jump if the value on stack is false
 */
#define OP_JMP_IF_ELSE 0x07

/**
 * Unconditional jump
 */
#define OP_JMP 0x08

/**
 * Returns global variables
 */
#define OP_GET_GLOBAL 0x09

/**
 * Sets global variables value
 */
#define OP_SET_GLOBAL 0x10

// -------------------------------------------------------

#define OP_STR(op)                                                             \
  case OP_##op:                                                                \
    return #op

std::string opcodeToString(uint8_t opcode) {
  switch (opcode) {
    OP_STR(HALT);
    OP_STR(CONST);
    OP_STR(ADD);
    OP_STR(SUB);
    OP_STR(MUL);
    OP_STR(DIV);
    OP_STR(COMPARE);
    OP_STR(JMP_IF_ELSE);
    OP_STR(JMP);
    OP_STR(GET_GLOBAL);
    OP_STR(SET_GLOBAL);
  default:
    DIE << "opcodeToString: unknown opcode: " << (int)opcode;
  }

  return "Unknown";
}

#endif
