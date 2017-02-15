#include "../include/alu_cu.hpp"

program_memory::program_memory(std::string program_file_name):
  instructions_()
  {
    std::ifstream program_file;
    program_file.open(program_file_name);
    if(program_file.is_open())
      std::clog << "The program file has been opened successfully." << std::endl;
    else
      std::cerr << "ERROR opening the program file." << std::endl;
      //throw

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
        //std::cout<<program_file_line<<std::endl;
        if(!valid_instruction(instruction_enums, instruction_parameter_string, instruction.parameter))
        {
          std::cerr << "Invalid instruction." << std::endl;
          std::cout<<program_file_line<<std::endl;
        }  //throw

        //validar entero por referencia
        //if(!valid)
        //throw

        //validar tag izquierdo

        //posible etiqueta
        if(tag_line.tag.size() > 0)
        {
          //////////////REVISAAAAR
          //////////////////////
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
    //pasar el los vectores de tags al vector de instrucciones
    //std::cout<<tags_vector.size()<<" etiquetas"<<std::endl;
    //std::cout<<jumps_vector.size()<<" saltos"<<std::endl;
    //for(unsigned int i = 0; i < jumps_vector.size(); i++)
      //std::cout<<"."<<(jumps_vector[i].tag)<<" size: "<<jumps_vector[i].tag.size()<<"."<<std::endl;
    //for(unsigned int i = 0; i < tags_vector.size(); i++)
      //std::cout<<"."<<tags_vector[i].tag.c_str()<<"."<<std::endl;

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
    else
      std::cerr << "ERROR in validation program." << std::endl;
    std::clog << "Compilation completed." << std::endl;
  }

bool program_memory::valid_program_memory(void)
{
  for(unsigned int i = 0; i < instructions_.size(); i++)
    if(instructions_[i].parameter == UNDEFINED)
      return(0);
  return(1);
}
instruction_t& program_memory::operator[](const int position)
{
  //throw si te sales
  return(instructions_[position]);
}
