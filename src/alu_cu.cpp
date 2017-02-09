#include "../include/alu_cu.hpp"

alu_cu::alu_cu(int ip):
  ip_(ip),
  program_memory_(),
  data_memory_()
  {}

void alu_cu::load_constant(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]=parameter;
}

void alu_cu::direct_addressing_load(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]=data_memory_[parameter];
}

void alu_cu::indirect_addressing_load(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]=data_memory_[data_memory_[parameter]];
}

void alu_cu::direct_addressing_store(int parameter)
{
  data_memory_[parameter]=data_memory_[ACCUMULATOR_REGISTER];
}

void alu_cu::indirect_addressing_store(int parameter)
{
  data_memory_[parameter]=data_memory_[data_memory_[ACCUMULATOR_REGISTER]];
}

void alu_cu::add_constant(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]+=parameter;
}

void alu_cu::direct_addressing_add(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]+=data_memory_[parameter];
}

void alu_cu::indirect_addressing_add(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]+=data_memory_[data_memory_[parameter]];
}

void alu_cu::sub_constant(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]-=parameter;
}

void alu_cu::direct_addressing_sub(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]-=data_memory_[parameter];
}

void alu_cu::indirect_addressing_sub(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]-=data_memory_[data_memory_[parameter]];
}

void alu_cu::mul_constant(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]*=parameter;
}

void alu_cu::direct_addressing_mul(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]*=data_memory_[parameter];
}

void alu_cu::indirect_addressing_mul(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]*=data_memory_[data_memory_[parameter]];
}

void alu_cu::div_constant(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]+=parameter;
}

void alu_cu::direct_addressing_div(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]+=data_memory_[parameter];
}

void alu_cu::indirect_addressing_div(int parameter)
{
  data_memory_[ACCUMULATOR_REGISTER]+=data_memory_[data_memory_[parameter]];
}

void alu_cu::jump(int parameter)
{
  ip_=parameter;
}

void alu_cu::jzero(int parameter)
{
  if(data_memory_[ACCUMULATOR_REGISTER] == 0)
    ip_=parameter;
}

void alu_cu::jgtz(int parameter)
{
  if(data_memory_[ACCUMULATOR_REGISTER] > 0)
    ip_=parameter;
}

void alu_cu::run(bool verbose)
{
  bool halt=0;
  if(verbose)
  {
    while(!halt)
    {
      if(program_memory_[ip_].run == nullptr)
        halt=1;
      else
      {
        //MOSTRAR
        (this->*(program_memory_[ip_].run))(program_memory_[ip_].parameter);
        ++ip_;
      }
      //throw ip<0
    }
  }
  else
  {
    while(!halt)
    {
      if(program_memory_[ip_].run == nullptr)
        halt=1;
      else
      {
        (this->*(program_memory_[ip_].run))(program_memory_[ip_].parameter);
        ++ip_;
      }
      //throw ip<0
    }
  }

}
