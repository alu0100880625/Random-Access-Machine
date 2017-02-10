#include "../include/input_unit_t.hpp"

input_unit_t::input_unit_t(std::string input_file_name):
  input_file(input_file_name) //revisar
  {
    if(input_file.is_open())
      std::clog << "The input file has been opened successfully." << std::endl;
    else
      std::cerr << "ERROR opening the input file" << std::endl;
     //throw
  }

input_unit_t::~input_unit_t(void)
{
  std::clog << "Closing input file." << std::endl;
  input_file.close();
}

data_memory_t input_unit_t::read(void)
{
  data_memory_t read_element;
  input_file >> read_element;
  return(read_element);
}
