#pragma once
#include <exception>
#include <iostream>
//clase base de las excepciones del la maquina RAM
class alu_cu_exception : public std::exception
{
  protected:
    std::string more_info_;
  public:
    alu_cu_exception(std::string more_info):
      more_info_(more_info)
      {}

    virtual const char * what (void) const throw () = 0;
};
//clase excepción con pundero de instructión inválido
class alu_cu_invalid_ip_exception : public alu_cu_exception
{
  public:
    alu_cu_invalid_ip_exception(std::string more_info):
      alu_cu_exception(more_info)
      {}

    const char * what (void) const throw ()
    {
      return std::string( "Run time error: invalid ip (with value: " + this -> more_info_ + ")." ).c_str();
    }
};
//clase excepción por acceso a la memoria de datos inválido
class alu_cu_invalid_data_memory_access_exception : public alu_cu_exception
{
  public:
    alu_cu_invalid_data_memory_access_exception(std::string more_info):
      alu_cu_exception(more_info)
      {}

    const char * what (void) const throw ()
    {
      return std::string( "Run time error: invalid data memory access (register: " + this -> more_info_ + ")." ).c_str();
    }
};
//clase excepción por fichero de entrada inválido
class alu_cu_invalid_input_file_exception : public alu_cu_exception
{
  public:
    alu_cu_invalid_input_file_exception(std::string more_info):
      alu_cu_exception(more_info)
      {}

    const char * what (void) const throw ()
    {
      return std::string( "Run time error: invalid input file (name: " + this -> more_info_ + ")." ).c_str();
    }
};
//clase excepción por fichero de salida inválido
class alu_cu_invalid_output_file_exception : public alu_cu_exception
{
  public:
    alu_cu_invalid_output_file_exception(std::string more_info):
      alu_cu_exception(more_info)
      {}

    const char * what (void) const throw ()
    {
      return std::string( "Run time error: invalid output file (name: " + this -> more_info_ + ")." ).c_str();
    }
};
//clase excepción por fichero de programa inválido
class alu_cu_invalid_program_file_exception : public alu_cu_exception
{
  public:
    alu_cu_invalid_program_file_exception(std::string more_info):
      alu_cu_exception(more_info)
      {}

    const char * what (void) const throw ()
    {
      return std::string( "Run time error: invalid output file (name: " + this -> more_info_ + ")." ).c_str();
    }
};
//clase excepción por instrucción inválida inválido
class alu_cu_invalid_instruction_exception : public alu_cu_exception
{
  public:
    alu_cu_invalid_instruction_exception(std::string more_info):
      alu_cu_exception(more_info)
      {}

    const char * what (void) const throw ()
    {
      return std::string( "Run time error: invalid instruction (" + this -> more_info_ + ")." ).c_str();
    }
};
//clase excepción por acceso a la memoria del programa inválido
class alu_cu_invalid_program_memory_access_exception : public alu_cu_exception
{
  public:
    alu_cu_invalid_program_memory_access_exception(std::string more_info):
      alu_cu_exception(more_info)
      {}

    const char * what (void) const throw ()
    {
      return std::string( "Run time error: invalid program memory access (instruction: " + this -> more_info_ + ")." ).c_str();
    }
};
