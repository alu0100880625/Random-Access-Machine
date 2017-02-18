#pragma once
#include <fstream>
#include "../include/common.hpp"
//clase que representa la unidad de salida
class output_unit_t
{
  private:
    std::ofstream output_file;  //fichero de salida
  public:
    //constructor de la clase que recibe el nombre del fichero de salida
    //puede lanzar una excepción si el fichero indicado no es accesible
    output_unit_t(std::string output_file_name);
    ~output_unit_t(void);
    //función que escribe en el fichero de salida un elemento indicado por parámetro
    void write(data_memory_t element);
};
