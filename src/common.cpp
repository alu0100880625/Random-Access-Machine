#include "../include/common.hpp"

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
  return(undefined_parameter);
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

std::string separate_tag(std::string &s, bool &found)
{
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
