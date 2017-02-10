#include "../include/alu_cu.hpp"

//derecha del operando


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
    //parse(line);
  }
  file.close();

}
