#include "../include/program_memory.hpp"

run_t create_instruction(instruction_enums_t instruction_enums);

run_t create_load_instruction(parameter_type_t parameter_type);
run_t create_store_instruction(parameter_type_t parameter_type);
run_t create_add_instruction(parameter_type_t parameter_type);
run_t create_sub_instruction(parameter_type_t parameter_type);
run_t create_mul_instruction(parameter_type_t parameter_type);
run_t create_div_instruction(parameter_type_t parameter_type);
run_t create_read_instruction(parameter_type_t parameter_type);
run_t create_write_instruction(parameter_type_t parameter_type);
