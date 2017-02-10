#pragma once
#include <algorithm>
#include <iostream>

#define UNDEFINED -2
#define NONE -3

typedef int data_memory_t;

enum instruction_type_t
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

enum parameter_type_t
{
  undefined_parameter,
  none,
  tag,
  constant,
  direct_addressing,
  indirect_addressing
};

struct instruction_enums_t
{
  instruction_type_t instruction_type;
  parameter_type_t parameter_type;
};

bool valid_instruction(instruction_enums_t instruction_enums, std::string parameter, int &final_parameter);

instruction_type_t analyze_instruction(std::string s);
parameter_type_t analyze_parameter(std::string s);

bool parse(std::string line, instruction_enums_t &instruction_enums, std::string &tag, std::string &parameter);

std::string remove_comments(std::string s);
std::string remove_beginning_blanks(std::string s);
std::string remove_back_blanks(std::string s);
std::string remove_first_character(std::string s);

std::string separate_tag(std::string &s/*, bool &found*/);
std::string separate_parameter(std::string &s);

bool no_blanks(std::string s);
bool is_blank(char x);
bool is_letter(char x);
bool is_number(char x);
bool is_number(std::string s);
