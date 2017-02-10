#pragma once
#include "../include/common.hpp"
#include <vector>

class alu_cu;

typedef void (alu_cu::*run_t)(int);

struct tag_line_t
{
  std::string tag;
  int line;
};

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
    program_memory(std::string program_file_name);
    //  program_memory(/*std::string program_file*/);
    //destructor
    bool valid_program_memory(void);
    instruction_t& operator[](const int position);
};
