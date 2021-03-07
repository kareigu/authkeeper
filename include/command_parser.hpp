#pragma once
#include "command_list.hpp"
#include <string>

struct CommandParser {
  CommandList* cmdlist;
  bool* return_to_main;

  CommandParser(CommandList* cmdlist, bool* return_to_main);
  ~CommandParser();

  void parse_command(std::string input);
};