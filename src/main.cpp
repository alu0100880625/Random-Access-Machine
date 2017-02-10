#include "../include/alu_cu.hpp"

//derecha del operando


int main(int argc, char *argv[])
{
  //mejorar
  alu_cu my_alu_cu(argv[1],argv[2],argv[3]);
  my_alu_cu.run(std::atoi(argv[4]));
}
