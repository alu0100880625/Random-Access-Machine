#include "../include/alu_cu.hpp"

alu_cu::alu_cu(std::string program_file_name, std::string input_file_name, std::string output_file_name):
  ip_(0),
  program_memory_(program_file_name),
  data_memory_(),
  input_unit(input_file_name),
  output_unit(output_file_name)
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
  data_memory_[ACCUMULATOR_REGISTER] = data_memory_[data_memory_[parameter]];
}

void alu_cu::direct_addressing_store(int parameter)
{
  data_memory_[parameter] = data_memory_[ACCUMULATOR_REGISTER];
}

void alu_cu::indirect_addressing_store(int parameter)
{
  data_memory_[parameter] = data_memory_[data_memory_[ACCUMULATOR_REGISTER]];
}

void alu_cu::add_constant(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] += parameter;
}

void alu_cu::direct_addressing_add(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] += data_memory_[parameter];
}

void alu_cu::indirect_addressing_add(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] += data_memory_[data_memory_[parameter]];
}

void alu_cu::sub_constant(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] -= parameter;
}

void alu_cu::direct_addressing_sub(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] -= data_memory_[parameter];
}

void alu_cu::indirect_addressing_sub(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] -= data_memory_[data_memory_[parameter]];
}

void alu_cu::mul_constant(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] *= parameter;
}

void alu_cu::direct_addressing_mul(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] *= data_memory_[parameter];
}

void alu_cu::indirect_addressing_mul(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER] *= data_memory_[data_memory_[parameter]];
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
  data_memory_[data_memory_[parameter]] = input_unit.read();
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
    output_unit.write(data_memory_[data_memory_[parameter]]);
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
    ip_=parameter;
}
/*
void alu_cu::run_instruction(void)
{
  if(program_memory_[ip_].run == &alu_cu::load_constant)
    load_constant(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::direct_addressing_load)
    direct_addressing_load(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::indirect_addressing_load)
    indirect_addressing_load(program_memory_[ip_].parameter);

  if(program_memory_[ip_].run == &alu_cu::direct_addressing_store)
    direct_addressing_store(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::indirect_addressing_store)
    indirect_addressing_store(program_memory_[ip_].parameter);

  if(program_memory_[ip_].run == &alu_cu::add_constant)
    add_constant(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::direct_addressing_add)
    direct_addressing_add(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::indirect_addressing_add)
    indirect_addressing_add(program_memory_[ip_].parameter);

  if(program_memory_[ip_].run == &alu_cu::sub_constant)
    sub_constant(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::direct_addressing_sub)
    direct_addressing_sub(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::indirect_addressing_sub)
    indirect_addressing_sub(program_memory_[ip_].parameter);

  if(program_memory_[ip_].run == &alu_cu::mul_constant)
    mul_constant(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::direct_addressing_mul)
    direct_addressing_mul(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::indirect_addressing_mul)
    indirect_addressing_mul(program_memory_[ip_].parameter);

  if(program_memory_[ip_].run == &alu_cu::div_constant)
    div_constant(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::direct_addressing_div)
    direct_addressing_div(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::indirect_addressing_div)
    indirect_addressing_div(program_memory_[ip_].parameter);

  if(program_memory_[ip_].run == &alu_cu::direct_addressing_read)
    direct_addressing_read(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::indirect_addressing_read)
    indirect_addressing_read(program_memory_[ip_].parameter);

  if(program_memory_[ip_].run == &alu_cu::write_constant)
    write_constant(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::direct_addressing_write)
    direct_addressing_write(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::indirect_addressing_write)
    indirect_addressing_write(program_memory_[ip_].parameter);

  if(program_memory_[ip_].run == &alu_cu::jump)
    jump(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::jzero)
    jzero(program_memory_[ip_].parameter);
  if(program_memory_[ip_].run == &alu_cu::jgtz)
    jgtz(program_memory_[ip_].parameter);
}
*/
void alu_cu::run(bool verbose)
{
  bool halt=0;
  if(verbose)
  {
    while(!halt)
    {
      if(program_memory_[ip_].run == nullptr && program_memory_[ip_].parameter == NONE)
        halt = 1;
      else
      {
        std::cout << "Instruction:" << std::endl;
        std::cout << program_memory_[ip_].line << std::endl;
        //mostrar registros
  //      run_instruction();
        (this->*(program_memory_[ip_].run))(program_memory_[ip_].parameter);

      }
      ++ip_;
      //throw ip<0
    }
  }
  else
  {
    while(!halt)
    {
      if(program_memory_[ip_].run == nullptr && program_memory_[ip_].parameter == NONE)
        halt = 1;
      else
      {
        (this->*(program_memory_[ip_].run))(program_memory_[ip_].parameter);
        //run_instruction();
          //std::cout<<"hola"<<std::endl;
      }
      ++ip_;
      //throw ip<0
    }
  }

}
