#pragma once
#include "command_list.hpp"
#include <string>

struct CommandParser {
  CommandList* cmdlist;

  CommandParser(CommandList* cmdlist);
  ~CommandParser();

  void parse_command(std::string input);
};