#include "../include/common.hpp"
#include <vector>
#include <fstream>

//derecha del operando
void parse(std::string line)
{
  std::string instruction = remove_comments(line);
  //si no es 0
  bool btag = 0;
  std::string tag = separate_tag(instruction,btag);
  instruction = remove_beginning_blanks(instruction);


  std::string parameter = separate_parameter(instruction);

    //analizar instruccion
  instruction_type_t instruction_type = analyze_instruction(instruction);

  parameter = remove_back_blanks(parameter);

  parameter_type_t parameter_type = analyze_parameter(parameter);
  //validate parameter
  //std::resto=rematar_operando(op);
  //std::cout<<sin_com<<" "<<op<<std::endl;

  if(btag)
    std::cout << tag << ":" << instruction << " " << parameter << std::endl;
  else
    std::cout/*<<"no tag:"*/<< instruction << " " << parameter << std::endl;
  //std::cout<<"size: "<<sin_com.size()<<std::endl;
}

int main(void)
{
  std::ifstream file;
  file.open("./program/test1.ram");
  if(!file.is_open())
  {
    std::cerr<<"ERROR"<<std::endl;
    return(0);
  }
  std::string line;
  int i=0;
  while(getline(file,line))
  {
    i++;
    parse(line);
  }
  file.close();

}
