#include "../include/alu_cu.hpp"

run_t create_instruction(instruction_enums_t instruction_enums)
{
  if(instruction_enums.instruction_type == load)
    return(create_load_instruction(instruction_enums.parameter_type));
  if(instruction_enums.instruction_type == store)
    return(create_store_instruction(instruction_enums.parameter_type));
  if(instruction_enums.instruction_type == add)
    return(create_add_instruction(instruction_enums.parameter_type));
  if(instruction_enums.instruction_type == sub)
    return(create_sub_instruction(instruction_enums.parameter_type));
  if(instruction_enums.instruction_type == mul)
    return(create_mul_instruction(instruction_enums.parameter_type));
  if(instruction_enums.instruction_type == divi)
    return(create_div_instruction(instruction_enums.parameter_type));
  if(instruction_enums.instruction_type == read)
    return(create_read_instruction(instruction_enums.parameter_type));
  if(instruction_enums.instruction_type == write)
    return(create_write_instruction(instruction_enums.parameter_type));
  if(instruction_enums.instruction_type == jump)
    return(&alu_cu::jump);
  if(instruction_enums.instruction_type == jzero)
    return(&alu_cu::jzero);
  if(instruction_enums.instruction_type == jgtz)
    return(&alu_cu::jgtz);
  return(nullptr);
}

run_t create_load_instruction(parameter_type_t parameter_type)
{
  if(parameter_type == constant)
    return(&alu_cu::load_constant);
  if(parameter_type == direct_addressing)
    return(&alu_cu::direct_addressing_load);
  if(parameter_type == indirect_addressing)
    return(&alu_cu::indirect_addressing_load);
  return(nullptr);
}

run_t create_store_instruction(parameter_type_t parameter_type)
{
  if(parameter_type == direct_addressing)
    return(&alu_cu::direct_addressing_store);
  if(parameter_type == indirect_addressing)
    return(&alu_cu::indirect_addressing_store);
  return(nullptr);
}

run_t create_add_instruction(parameter_type_t parameter_type)
{
  if(parameter_type == constant)
    return(&alu_cu::add_constant);
  if(parameter_type == direct_addressing)
    return(&alu_cu::direct_addressing_add);
  if(parameter_type == indirect_addressing)
    return(&alu_cu::indirect_addressing_add);
  return(nullptr);
}

run_t create_sub_instruction(parameter_type_t parameter_type)
{
  if(parameter_type == constant)
    return(&alu_cu::sub_constant);
  if(parameter_type == direct_addressing)
    return(&alu_cu::direct_addressing_sub);
  if(parameter_type == indirect_addressing)
    return(&alu_cu::indirect_addressing_sub);
  return(nullptr);
}

run_t create_mul_instruction(parameter_type_t parameter_type)
{
  if(parameter_type == constant)
    return(&alu_cu::mul_constant);
  if(parameter_type == direct_addressing)
    return(&alu_cu::direct_addressing_mul);
  if(parameter_type == indirect_addressing)
    return(&alu_cu::indirect_addressing_mul);
  return(nullptr);
}

run_t create_div_instruction(parameter_type_t parameter_type)
{
  if(parameter_type == constant)
    return(&alu_cu::div_constant);
  if(parameter_type == direct_addressing)
    return(&alu_cu::direct_addressing_div);
  if(parameter_type == indirect_addressing)
    return(&alu_cu::indirect_addressing_div);
  return(nullptr);
}

run_t create_read_instruction(parameter_type_t parameter_type)
{
  if(parameter_type == constant)
    return(nullptr);
  if(parameter_type == direct_addressing)
    return(&alu_cu::direct_addressing_read);
  if(parameter_type == indirect_addressing)
    return(&alu_cu::indirect_addressing_read);
  return(nullptr);
}

run_t create_write_instruction(parameter_type_t parameter_type)
{
  if(parameter_type == constant)
    return(&alu_cu::write_constant);
  if(parameter_type == direct_addressing)
    return(&alu_cu::direct_addressing_write);
  if(parameter_type == indirect_addressing)
    return(&alu_cu::indirect_addressing_write);
  return(nullptr);
}
