#include "../include/alu_cu.hpp"

instruction_t& program_memory::operator[](const int position)
{
  //throw si te sales
  return(instructions_[position]);
}
