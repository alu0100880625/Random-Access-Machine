#include "../include/alu_cu.hpp"

alu_cu::alu_cu(std::string program_file_name, std::string input_file_name, std::string output_file_name):
  ip_(0),
  program_memory_(program_file_name),
  data_memory_(),
  input_unit(input_file_name),
  output_unit(output_file_name)
  {}

alu_cu::~alu_cu(void)
{}

void alu_cu::load_constant(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] = parameter;
}

void alu_cu::direct_addressing_load(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] = data_memory_[parameter];
}

void alu_cu::indirect_addressing_load(int parameter)
{
  int aux = data_memory_[parameter];
  data_memory_[ACCUMULATOR_REGISTER] = data_memory_[aux];
}

void alu_cu::direct_addressing_store(int parameter)
{
  data_memory_[parameter] = data_memory_[ACCUMULATOR_REGISTER];
}

void alu_cu::indirect_addressing_store(int parameter)
{
  int aux = data_memory_[parameter];
  int aux2 = data_memory_[ACCUMULATOR_REGISTER];
  data_memory_[aux] = aux2;
}

void alu_cu::add_constant(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] = data_memory_[ACCUMULATOR_REGISTER] + parameter;
}

void alu_cu::direct_addressing_add(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] = data_memory_[ACCUMULATOR_REGISTER] + data_memory_[parameter];
}

void alu_cu::indirect_addressing_add(int parameter)
{
  int aux = data_memory_[parameter];
  data_memory_[ACCUMULATOR_REGISTER] += data_memory_[ACCUMULATOR_REGISTER] + data_memory_[aux];
}

void alu_cu::sub_constant(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] = data_memory_[ACCUMULATOR_REGISTER] - parameter;
}

void alu_cu::direct_addressing_sub(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] = data_memory_[ACCUMULATOR_REGISTER] - data_memory_[parameter];
}

void alu_cu::indirect_addressing_sub(int parameter)
{
  int aux = data_memory_[parameter];
  data_memory_[ACCUMULATOR_REGISTER] = data_memory_[ACCUMULATOR_REGISTER] - data_memory_[aux];
}

void alu_cu::mul_constant(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] = data_memory_[ACCUMULATOR_REGISTER] * parameter;
}

void alu_cu::direct_addressing_mul(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] = data_memory_[ACCUMULATOR_REGISTER] * data_memory_[parameter];
}

void alu_cu::indirect_addressing_mul(int parameter)
{
  int aux = data_memory_[parameter];
  data_memory_[ACCUMULATOR_REGISTER] = data_memory_[ACCUMULATOR_REGISTER] * data_memory_[aux];
}

void alu_cu::div_constant(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] += parameter;
}

void alu_cu::direct_addressing_div(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] += data_memory_[parameter];
}

void alu_cu::indirect_addressing_div(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] += data_memory_[data_memory_[parameter]];
}

void alu_cu::direct_addressing_read(int parameter)
{
  data_memory_[parameter] = input_unit.read();
}

void alu_cu::indirect_addressing_read(int parameter)
{
  int aux = data_memory_[parameter];
  data_memory_[aux] = input_unit.read();
}

void alu_cu::write_constant(int parameter)
{
  output_unit.write(parameter);
}

void alu_cu::direct_addressing_write(int parameter)
{
  output_unit.write(data_memory_[parameter]);
}

void alu_cu::indirect_addressing_write(int parameter)
{
  int aux = data_memory_[parameter];
  output_unit.write(data_memory_[aux]);
}

void alu_cu::jump(int parameter)
{
  ip_ = parameter;
}

void alu_cu::jzero(int parameter)
{
  if(data_memory_[ACCUMULATOR_REGISTER] == 0)
    ip_ = parameter;
}

void alu_cu::jgtz(int parameter)
{
  if(data_memory_[ACCUMULATOR_REGISTER] > 0)
    ip_ = parameter;
}

void alu_cu::run(bool debug)
{
  bool halt=0;
  if(debug)
  {
    while(!halt)
    {
      if(ip_ < 0)
        throw(alu_cu_invalid_ip_exception(std::to_string(ip_)));
      std::cout << "IP: "  << ip_ << std::endl;
      std::cout << "Instruction:" << std::endl;
      std::cout << program_memory_[ip_].line << std::endl;
      std::cout << "Registros: " << std::endl;
      std::cout << data_memory_ << std::endl;
      if(program_memory_[ip_].run == nullptr && program_memory_[ip_].parameter == NONE)
        halt = 1;
      else
        (this->*(program_memory_[ip_].run))(program_memory_[ip_].parameter);
      ++ip_;
    }
  }
  else
  {
    while(!halt)
    {
      if(ip_ < 0)
        throw(alu_cu_invalid_ip_exception(std::to_string(ip_)));
      if(program_memory_[ip_].run == nullptr && program_memory_[ip_].parameter == NONE)
        halt = 1;
      else
        (this->*(program_memory_[ip_].run))(program_memory_[ip_].parameter);
      ++ip_;
    }
  }
}
