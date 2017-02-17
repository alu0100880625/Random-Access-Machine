#pragma once
#include <vector>
#include "../include/common.hpp"

#define RESET_REGISTER 0
#define ACCUMULATOR_REGISTER 0

class data_memory
{
  private:
    std::vector<data_memory_t> memory_;
  public:
    data_memory(void);
    ~data_memory(void);
    void resize(const int position);
    data_memory_t& operator[](const int position);

    std::ostream& view(std::ostream &os) const;
    friend std::ostream& operator<<(std::ostream &os, const data_memory memory);
};
