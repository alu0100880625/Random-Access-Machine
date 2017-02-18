#pragma once
#include "../include/data_memory.hpp"
#include "../include/instructions.hpp"
#include "../include/input_unit_t.hpp"
#include "../include/output_unit_t.hpp"
//clase que representa la unidad de control y la unidad aritmético-lógica
class alu_cu
{
  private:
    int ip_;  //puntero de instrucción
    program_memory program_memory_; //memoria del porgrama
    data_memory data_memory_; //memoria de datos
    input_unit_t input_unit;  //entrada de datos
    output_unit_t output_unit;  //salida de datos
  public:
    //constructor de la clase que recibe los nombres de los ficheros del programa, entrada y salida
    alu_cu(std::string program_file_name, std::string input_file_name, std::string output_file_name);
    ~alu_cu(void);  //destructor de la clase

    void load_constant(int parameter);
    void direct_addressing_load(int parameter);
    void indirect_addressing_load(int parameter);

    void direct_addressing_store(int parameter);
    void indirect_addressing_store(int parameter);

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

    void direct_addressing_read(int parameter);
    void indirect_addressing_read(int parameter);

    void write_constant(int parameter);
    void direct_addressing_write(int parameter);
    void indirect_addressing_write(int parameter);

    void jump(int parameter);
    void jzero(int parameter);
    void jgtz(int parameter);

    void run(bool debug); //ejecuta las instrucciones mostrando traza o sin mostrar en funcion del bool
};
