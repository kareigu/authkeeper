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

  try {
    int num = std::stoi(input);
    logger::print(this->cmdlist->loadkey_cmd(num));

  } catch(const std::exception& e) {
    
    if(input == "exit" || input == "quit")
      this->cmdlist->exit_cmd(); 
    else if(input == "edit")
      this->cmdlist->edit_cmd();
    else
      logger::print("Invalid command");
  }
}