#include "../include/common.hpp"

bool valid_instruction(instruction_enums_t instruction_enums, std::string parameter, int &final_parameter)
{
//  bool valid = 0;
//  bool baux = 0;
  //bool valid_jump = 0;
  if( instruction_enums.parameter_type == undefined_parameter || instruction_enums.instruction_type == undefined_instruction)
    //throw no reconocido
    return(0);

  if(instruction_enums.parameter_type == none)
  {
    if(instruction_enums.instruction_type == halt)
    {
      final_parameter = NONE;
      return(1);
    }
    else
      return(0);
  }
  if(!no_blanks(parameter))
    //throw invalid
    return(0);

  if(instruction_enums.instruction_type == jump ||
     instruction_enums.instruction_type == jzero ||
     instruction_enums.instruction_type == jgtz)
  {
    final_parameter = UNDEFINED;
    return(instruction_enums.parameter_type == tag);
  }

  if(instruction_enums.parameter_type == tag)
    return(0);

  if(((instruction_enums.instruction_type == store) || (instruction_enums.instruction_type == read)) &&
     instruction_enums.parameter_type == constant)
  {
    //throw
    return(0);
  }

  if(instruction_enums.parameter_type == constant || instruction_enums.parameter_type == indirect_addressing)
    parameter=remove_first_character(parameter);

  final_parameter = std::atoi(parameter.c_str());
  if(final_parameter == 0 && (instruction_enums.instruction_type == read || instruction_enums.instruction_type == write))
    return(0);
  return(1);
}

instruction_type_t analyze_instruction(std::string s)
{
  std::transform(s.begin(), s.end(), s.begin(), ::toupper);
  if(s.compare("LOAD") == 0)
    return(load);
  if(s.compare("STORE") == 0)
    return(store);
  if(s.compare("ADD") == 0)
    return(add);
  if(s.compare("SUB") == 0)
    return(sub);
  if(s.compare("MUL") == 0)
    return(mul);
  if(s.compare("DIV") == 0)
    return(divi);
  if(s.compare("READ") == 0)
    return(read);
  if(s.compare("WRITE") == 0)
    return(write);
  if(s.compare("JUMP") == 0)
    return(jump);
  if(s.compare("JZERO") == 0)
    return(jzero);
  if(s.compare("JGTZ") == 0)
    return(jgtz);
  if(s.compare("HALT") == 0)
    return(halt);
  return(undefined_instruction);
}

parameter_type_t analyze_parameter(std::string s)
{
  if(!no_blanks(s))
    return(undefined_parameter);
  if(is_letter(s[0]))
    return(tag);
  if(s[0] == '=')
    return(constant);
  if(is_number(s[0]))
    return(direct_addressing);
  if(s[0] == '*')
    return(indirect_addressing);
  if(s.size() == 0)
    return(none);
  return(undefined_parameter);
}

bool parse(std::string line, instruction_enums_t &instruction_enums, std::string &tag, std::string &parameter)
{
  std::string instruction = remove_comments(line);
  //si no es 0
  if(instruction.size() == 0)
    return(0);
  //bool btag = 0;
  tag = separate_tag(instruction/*, btag*/);
  instruction = remove_beginning_blanks(instruction);

  parameter = separate_parameter(instruction);
    //analizar instruccion
  instruction_enums.instruction_type = analyze_instruction(instruction);

  parameter = remove_back_blanks(parameter);

  instruction_enums.parameter_type = analyze_parameter(parameter);

  return(1);
}

std::string remove_comments(std::string s)
{
  std::string aux = "";
  unsigned int pos = 0;
  while( pos < s.size() && s[pos] != '#' )
  {
    aux = aux + s[pos];
    pos++;
  }
  return(aux);
}

std::string remove_beginning_blanks(std::string s)
{
  std::string aux = "";
  unsigned int pos = 0;
  while( pos < s.size() && is_blank(s[pos]) )
    pos++;
  for(unsigned int i = pos; i < s.size(); i++)
    aux += s[i];
  return(aux);
}

std::string remove_back_blanks(std::string s)
{
  std::string aux = "";
  int pos = s.size() - 1;
  while( pos >= 0 && is_blank(s[pos]) )
    pos--;
  for(int i = 0; i <= pos; i++)
    aux += s[i];
  return(aux);
}

std::string remove_first_character(std::string s)
{
  std::string aux = "";
  for(unsigned int i = 1; i < s.size(); i++)
    aux += s[i];
  return(aux);
}

std::string separate_tag(std::string &s/*, bool &found*/)
{
  bool found = 0;
  std::string aux = "";
  unsigned int pos = 0;
  while( pos < s.size() && s[pos] != ':' )
  {
    aux += s[pos];
    pos++;
  }
  found = s[pos] == ':';
  if(found)
  {
    std::string copy_s = s.c_str();
    s = "";
    for(unsigned int i = pos + 1; i < copy_s.size(); i++)
      s += copy_s[i];
  }
  else
    aux = "";
  return(aux);
}

std::string separate_parameter(std::string &s)
{
  std::string aux = "";
  unsigned int pos = 0;
  while( (pos < s.length()) && is_letter(s[pos]))
    pos++;
  for(unsigned int i = pos; i < s.size(); i++)
    aux += s[i];
  aux = remove_beginning_blanks(aux);
  std::string copy_s = s.c_str();
  s = "";
  for(unsigned int i = 0; i < pos; i++)
    s += copy_s[i];
  return(aux);
}

bool no_blanks(std::string s)
{
  for(unsigned int i = 0; i < s.size(); i++)
    if(is_blank(s[i]))
      return(0);
  return(1);
}

bool is_blank(char x)
{
  return( x == ' ' || x == '\t' );
}

bool is_letter(char x)
{
  return((( x >= 'a') && ( x <= 'z')) || (( x >= 'A') && ( x <='Z' )));
}

bool is_number(char x)
{
  return((x >= '0') && (x <= '9'));
}

bool is_number(std::string s)
{
  for(unsigned int i = s[0] == '-'; i < s.size(); i++)
    if(!is_number(s[i]))
      return(0);
  return(1);
}
