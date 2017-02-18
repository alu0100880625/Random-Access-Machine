#include "../include/alu_cu.hpp"

void usage(void)
{
  std::cout << "Type of parameter:" << std::endl;
  std::cout << "\tConstant(C): =number" << std::endl;
  std::cout << "\tDirect addressing(DA): number" << std::endl;
  std::cout << "\tIndirect addressing(IA): *number" << std::endl;
  std::cout << "\tTag(T): tag" << std::endl;
  std::cout << "\tNone(N):" << std::endl;
  std::cout << "Type of instructions:" << std::endl;
  std::cout << "\tLOAD: [C|DA|IA]" << std::endl;
  std::cout << "\tSTORE: [DA|IA]" << std::endl;
  std::cout << "\tADD: [C|DA|IA]" << std::endl;
  std::cout << "\tSUB: [C|DA|IA]" << std::endl;
  std::cout << "\tMUL: [C|DA|IA]" << std::endl;
  std::cout << "\tDIV: [C|DA|IA]" << std::endl;
  std::cout << "\tREAD: [DA(not 0)|IA]" << std::endl;
  std::cout << "\tWRITE: [C|DA(not 0)|IA]" << std::endl;
  std::cout << "\tJUMP: [T]" << std::endl;
  std::cout << "\tJZERO: [T]" << std::endl;
  std::cout << "\tJGTZ: [T]" << std::endl;
  std::cout << "\tHATT: [N]" << std::endl;
  std::cout << "Instructions:" << std::endl;
  std::cout << "\t<T:>INSTRUCTION PARAMETER" << std::endl;
  std::cout << "Usage: ./bin/ram_sim program_file_name input_file_name output_file_name debug" << std::endl;
}

int main(int argc, char *argv[])
{
  if(argc < 5)
  {
    usage();
    return(1);
  }
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
    std::cerr << "ERROR: se ha lanzado una excepción no reconocida" << std::endl;
  }
}
