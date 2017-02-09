#pragma once
#include "../include/common.hpp"
#include <vector>

class alu_cu;

typedef void (alu_cu::*run_t)(int);

struct instruction_t
{
  std::string line;
  int parameter;
  run_t run;
};

class program_memory
{
  private:
    std::vector<instruction_t> instructions_;
  public:

    instruction_t& operator[](const int position);
};
