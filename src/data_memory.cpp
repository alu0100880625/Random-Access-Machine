#include "../include/data_memory.hpp"

data_memory::data_memory(void):
  memory_(1,RESET_REGISTER)
  {}

data_memory::~data_memory(void)
{}

void data_memory::resize(const unsigned int position)
{
  while(position >= memory_.size())
    memory_.push_back(RESET_REGISTER);
}

data_memory_t& data_memory::operator[](const unsigned int position)
{
  //if <0 throw
  if(position >= memory_.size())
    resize(position);
  return(memory_[position]);
}
