#include "../include/data_memory.hpp"

data_memory::data_memory(void):
  memory_(1,RESET_REGISTER)
  {}

data_memory::~data_memory(void)
{}

void data_memory::resize(const unsigned int position)
{
  memory_.resize(position,RESET_REGISTER);
  memory_.push_back(RESET_REGISTER);
}

data_memory_t& data_memory::operator[](const unsigned int position)
{
  //if <0 throw
  if(position >= memory_.size())
    resize(position);
  return(memory_[position]);
}

std::ostream& data_memory::view(std::ostream &os) const
{
  for(unsigned int i = 0; i < memory_.size(); i++)
    os << std::setw(5) << i << " ";
  os << std::endl;
  for(unsigned int i = 0; i < memory_.size(); i++)
    os << std::setw(5) << memory_[i] << " ";
  os << std::endl;
  return(os);
}

std::ostream& operator<<(std::ostream &os, const data_memory memory)
{
  return(memory.view(os));
}
