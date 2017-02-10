#pragma once
#include "../include/data_memory.hpp"
#include "../include/program_memory.hpp"
#include "../include/input_unit_t.hpp"
#include "../include/output_unit_t.hpp"

class alu_cu
{
  private:
    int ip_;
    program_memory program_memory_;
    data_memory data_memory_;
    //input
    //output

  public:
    alu_cu(int ip);
    //destructor
    void load_constant(int parameter);
    void direct_addressing_load(int parameter);
    void indirect_addressing_load(int parameter);
    //void store_const(int parameter)

    void direct_addressing_store(int parameter);
//////////////////////////////////////////
/////////////REVISAR//////////////////////
//////////////////////////////////////////
    void indirect_addressing_store(int parameter);
////////////////////////////////////////////
    void add_constant(int parameter);
    void direct_addressing_add(int parameter);
    void indirect_addressing_add(int parameter);

    void sub_constant(int parameter);
    void direct_addressing_sub(int parameter);
    void indirect_addressing_sub(int parameter);

    void mul_constant(int parameter);
    void direct_addressing_mul(int parameter);
    void indirect_addressing_mul(int parameter);

    void div_constant(int parameter);
    void direct_addressing_div(int parameter);
    void indirect_addressing_div(int parameter);
    ////////////////////////////////////////////////////
    ////////////READ Y WRITE////////////////////////////
    ////////////////////////////////////////////////////

    void jump(int parameter);

    void jzero(int parameter);

    void jgtz(int parameter);

    void run(bool verbose);
};
