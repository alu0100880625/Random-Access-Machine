#include "../include/alu_cu.hpp"

//derecha del operando
//read

int main(int argc, char *argv[])
{
  //mejorar
  //throw
  //usage
  try
  {
    alu_cu my_alu_cu(argv[1],argv[2],argv[3]);
    my_alu_cu.run(std::atoi(argv[4]));
  }
  catch(const std::exception &exception)
  {
    std::cerr << exception.what() << std::endl;
  }
  catch(...)
  {
    std::cerr << "No reconocida" << std::endl;
  }
}
