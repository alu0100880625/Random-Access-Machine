#pragma once
#include <vector>
#define RESET_REGISTER 0
#define ACCUMULATOR_REGISTER 0

typedef int data_memory_t;

class data_memory
{
  private:
    std::vector<data_memory_t> memory_;
  public:
    data_memory(void);
    ~data_memory(void);
    void resize(const unsigned int position);
    data_memory_t& operator[](const unsigned int position);
};
