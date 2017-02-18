#pragma once
#include "../include/common.hpp"
#include <vector>

class alu_cu;

typedef void (alu_cu::*run_t)(int);//puntero a una función void de la alu_cu que recibe un entero por parámetro
//struct utilizado para las etiquetas de salto
//y para las instrucciones situadas en una etiqueta
struct tag_line_t
{
  int line;
  std::string tag;
};
//struct que contiene la información de las instrucciones
struct instruction_t
{
  std::string line; //string que contiene la línea de la instrucción
  int parameter;  //parámetro que se le pasa a la función
  run_t run;  //función a ejecutar
};
//clase que representa la memoria del programa
class program_memory
{
  private:
    std::vector<instruction_t> instructions_; //vector de instrucciones
  public:
    //constructor de la clase que recibe el nombre del fichero del programa
    //puede lanzar una excepción si el fichero indicado no es accesible
    //puede lanzar una excepción si alguna instrucción es inválida
    program_memory(std::string program_file_name);
    ~program_memory(void);
    //función que comprueba si el programa es válido
    //puede lanzar una excepción indicando la primera instrucción inválida que encuentre
    bool valid_program_memory(void);
    //sobrecarga del operador [] que permite acceder a la posicion indicada por parámetro
    //lanza una excepción si la posición esta fuera del vector
    instruction_t& operator[](const int position);
};
