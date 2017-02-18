#pragma once
#include <fstream>
#include "../include/common.hpp"
//clase que representa la unidad de entrada
class input_unit_t
{
  private:
    std::ifstream input_file; //fichero de entrada
  public:
    //constructor de la clase que recibe el nombre del fichero de entrada
    //puede lanzar una excepción si el fichero indicado no es accesible
    input_unit_t(std::string input_file_name);
    ~input_unit_t(void);
    //función que lee un elemento y lo retorna
    data_memory_t read(void);
};
