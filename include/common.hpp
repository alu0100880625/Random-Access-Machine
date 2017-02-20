#pragma once
#include "../include/alu_cu_exception.hpp"
#include <algorithm>
#include <iomanip>

#define UNDEFINED -2  //constante que indica que aún no se ha encontrad el ip al que saltar
#define NONE -3 //constante que indica que esta instrucción no tiene parámetro

typedef int data_memory_t;  //tipo de dato de la memoria de datos

enum instruction_type_t //tipos de instrucciones
{
  undefined_instruction,
  load,
  store,
  add,
  sub,
  mul,
  divi,
  read,
  write,
  jump,
  jzero,
  jgtz,
  halt
};

enum parameter_type_t //tipos de parámetros
{
  undefined_parameter,
  none,
  tag,
  constant,
  direct_addressing,
  indirect_addressing
};

struct instruction_enums_t  //struct que contiene el tipo de instrucción con su correspondiente parámetro
{
  instruction_type_t instruction_type;
  parameter_type_t parameter_type;
};
// instrucción que comprueba si una instrucción es válida basandose en su tipo y su tipo de parámetro, recibe también
// su parámetro y modifica el entero pasado por referencia indicando el valor final
bool valid_instruction(instruction_enums_t instruction_enums, std::string parameter, int &final_parameter);
//recibe una instrucción y retorna un enum que indica que tipo de instrucción es
instruction_type_t analyze_instruction(std::string s);
//recibe un parámetro y retorna un enum que indica que tipo de parámetro es
parameter_type_t analyze_parameter(std::string s);
//función a la que se le pasa una línea del programa y retorna un true si la línea no es vacía
//tambien modifica el struct pasado por referencia indicando el tipo del parámetro y el tipo de instrucción
//finalmente también modifica las strings de etiqueta y parámetro pasadas por referencia
bool parse(std::string line, instruction_enums_t &instruction_enums, std::string &tag, std::string &parameter);
//función que recibe una string y retorna otra en la que se han eliminado los comentarios
std::string remove_comments(std::string s);
//función que recibe una string y retorna otra sin carácteres de espaciado al inicio
std::string remove_beginning_blanks(std::string s);
//función que recibe una string y retorna otra sin carácteres de espaciado al final
std::string remove_back_blanks(std::string s);
//función que recibe una string y retorna otra sin el primer carácter
std::string remove_first_character(std::string s);

std::string separate_tag(std::string &s);
std::string separate_parameter(std::string &s);
//función que indica si la string que se le pasa contiene carácteres de espaciado
bool no_blanks(std::string s);
//función que indica si el carácter que le pasamos es un carácter de espaciado
bool is_blank(char x);
//función que indica si el carácter que le pasamos es una letra
bool is_letter(char x);
//función que indica si el carácter que le pasamos es un número
bool is_number(char x);
//función que indica si la string que se le pasa es un número
bool is_number(std::string s);
