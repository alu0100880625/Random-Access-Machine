#include "../include/data_memory.hpp"

data_memory::data_memory(void):
  memory_(1,RESET_REGISTER)
  {}

data_memory::~data_memory(void)
{}

void data_memory::resize(const int position)
{
  memory_.resize(position,RESET_REGISTER);
  memory_.push_back(RESET_REGISTER);
}

data_memory_t& data_memory::operator[](const int position)
{
  if( position < 0 )
    throw(alu_cu_invalid_data_memory_access_exception(std::to_string(position)));
  if( unsigned(position) >= memory_.size())
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
