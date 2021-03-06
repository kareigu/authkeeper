#include "command_parser.hpp"
#include "command_list.hpp"
#include "logger.hpp"
#include <string>

CommandParser::CommandParser(CommandList* cmdlist) {
  this->cmdlist = cmdlist;
}

CommandParser::~CommandParser() {
  delete this->cmdlist;
}

void CommandParser::parse_command(std::string input) {

  if(input == "exit")
    this->cmdlist->exit_cmd();
  else if(input == "load")
    logger::print(this->cmdlist->loadkey_cmd(0));
  else if(input == "edit")
    this->cmdlist->edit_cmd();
  else
    logger::print("Invalid command");
}