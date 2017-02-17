#include "../include/alu_cu.hpp"

program_memory::program_memory(std::string program_file_name):
  instructions_()
  {
    std::ifstream program_file;
    program_file.open(program_file_name);
    if(program_file.is_open())
      std::clog << "The program file has been opened successfully." << std::endl;
    else
      throw(new alu_cu_invalid_program_file_exception(program_file_name));
    std::clog << "Compiling program.." << std::endl;
    std::string program_file_line, instruction_parameter_string;
    //REVISAR EL PARAMETRO
    instruction_t instruction;
    int line_counter=0;
    std::vector<tag_line_t> tags_vector, jumps_vector;
    tag_line_t tag_line;
    instruction_enums_t instruction_enums;
    while(getline(program_file, program_file_line))
    {
      if(parse(program_file_line, instruction_enums, tag_line.tag, instruction_parameter_string))
      {
        if(!valid_instruction(instruction_enums, instruction_parameter_string, instruction.parameter))
        {
          std::string info = "line ";
          info += (line_counter + 1);
          info +=": ";
          info += program_file_line;
          program_file.close();
          throw(new alu_cu_invalid_instruction_exception(info));
        }
        //validar entero por referencia
        //validar tag izquierdo

        //posible etiqueta
        if(tag_line.tag.size() > 0)
        {
          tag_line.line = line_counter -1 ;
          tags_vector.push_back(tag_line);
        }
        //posible argumento etiqueta
        if(instruction_enums.parameter_type == tag)
        {
          tag_line.tag = instruction_parameter_string;
          tag_line.line = line_counter;
          jumps_vector.push_back(tag_line);
        }
        instruction.line = program_file_line;
        instruction.run = create_instruction(instruction_enums);
        instructions_.push_back(instruction);
        //crear instruccion
        //insertar instruccion
        ++line_counter;
      }
      //else blank line
    }
    std::clog << "Closing program file." << std::endl;
    program_file.close();
    for(unsigned int i = 0; i < jumps_vector.size(); i++)
      for(unsigned int j = 0; j < tags_vector.size(); j++)
        if(jumps_vector[i].tag.compare(tags_vector[j].tag) == 0)
        {
          instructions_[jumps_vector[i].line].parameter = tags_vector[j].line;
          j = tags_vector.size();
        }
    //valid_all
    std::clog << "Validating program.." << std::endl;
    if(valid_program_memory())
      std::clog << "The program has been successfully validated." << std::endl;
    std::clog << "Compilation completed." << std::endl;
  }

program_memory::~program_memory(void)
{}

bool program_memory::valid_program_memory(void)
{
  for(unsigned int i = 0; i < instructions_.size(); i++)
    if(instructions_[i].parameter == UNDEFINED)
    {
      std::string info = "line ";
      info += (i + 1);
      info +=": ";
      info += instructions_[i].line;
      throw (new alu_cu_invalid_instruction_exception((info)));
    }
  return(1);
}

instruction_t& program_memory::operator[](const int position)
{
  if(position < 0)
    throw(new alu_cu_invalid_program_memory_access_exception(std::to_string(position)));
  return(instructions_[position]);
}
