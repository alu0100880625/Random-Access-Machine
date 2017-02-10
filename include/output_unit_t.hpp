#pragma once
#include <fstream>
#include "../include/common.hpp"

class output_unit_t
{
  private:
    std::ofstream output_file;
  public:
    output_unit_t(std::string output_file_name);
    ~output_unit_t(void);
    void write(data_memory_t element);
};
