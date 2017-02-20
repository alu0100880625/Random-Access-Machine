#include "../include/output_unit_t.hpp"

output_unit_t::output_unit_t(std::string output_file_name):
  output_file()
  {
    output_file.open(output_file_name);
    if(output_file.is_open())
      std::clog << "The output file has been opened successfully." << std::endl;
    else
      throw(alu_cu_invalid_output_file_exception(output_file_name));
  }

output_unit_t::~output_unit_t(void)
{
  std::clog << "Closing output file." << std::endl;
  output_file.close();
}

void output_unit_t::write(data_memory_t element)
{
  output_file << element << " ";
}
