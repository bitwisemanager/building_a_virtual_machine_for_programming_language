#include "eva_vm.h"

/**
 * Eva VM main executable
 */
int main(int argc, char const **argv) {

  EvaVM vm;

  vm.exec(R"(
    42
  )");

  return 0;
}