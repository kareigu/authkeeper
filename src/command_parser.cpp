#include "command_parser.hpp"
#include "command_list.hpp"
#include "logger.hpp"
#include <string>

CommandParser::CommandParser(CommandList* cmdlist, bool* return_to_main) {
  this->cmdlist = cmdlist;
  this->return_to_main = return_to_main;
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
      this->cmdlist->exit_cmd(this->return_to_main); 
    else if(input == "edit")
      this->cmdlist->edit_cmd();
    else if(input == "help")
      this->cmdlist->help_cmd();
    else if(input == "config")
      this->cmdlist->config_cmd();
    else
      logger::print("Invalid command");
  }
}