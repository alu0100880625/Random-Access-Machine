#pragma once
#include "../include/program_memory.hpp"
//función que retorna el puntero a la función basándose en el struct de tipo de instrucción y tipo de parámetro
run_t create_instruction(instruction_enums_t instruction_enums);
//función que retorna el puntero función de load basandose en su tipo de parámetro
run_t create_load_instruction(parameter_type_t parameter_type);
//función que retorna el puntero función de store basandose en su tipo de parámetro
run_t create_store_instruction(parameter_type_t parameter_type);
//función que retorna el puntero función de add basandose en su tipo de parámetro
run_t create_add_instruction(parameter_type_t parameter_type);
//función que retorna el puntero función de sub basandose en su tipo de parámetro
run_t create_sub_instruction(parameter_type_t parameter_type);
//función que retorna el puntero función de mul basandose en su tipo de parámetro
run_t create_mul_instruction(parameter_type_t parameter_type);
//función que retorna el puntero función de div basandose en su tipo de parámetro
run_t create_div_instruction(parameter_type_t parameter_type);
//función que retorna el puntero función de read basandose en su tipo de parámetro
run_t create_read_instruction(parameter_type_t parameter_type);
//función que retorna el puntero función de write basandose en su tipo de parámetro
run_t create_write_instruction(parameter_type_t parameter_type);
