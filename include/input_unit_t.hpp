#pragma once
#include <fstream>
#include "../include/common.hpp"

class input_unit_t
{
  private:
    std::ifstream input_file;
  public:
    input_unit_t(std::string input_file_name);
    ~input_unit_t(void);
    data_memory_t read(void);
};
