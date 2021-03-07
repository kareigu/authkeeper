#include <string>
#include "command_list.hpp"
#include "logger.hpp"

CommandList::CommandList(Keylist* keylist, Config* config) {
  this->keylist = keylist;
  this->config = config;
}

CommandList::~CommandList() {
  delete this->keylist;
  delete this->config;
}


//*
//* Commands
//*

void CommandList::exit_cmd(bool* return_to_main) {
  logger::print("Exiting");
  *return_to_main = false;
}

std::string CommandList::loadkey_cmd(int index) {
  std::string row_value = this->keylist->keys[index - 1];
  if(index <= 0 || index > 300 || row_value.empty())
    return "Invalid row";
  else
    return "#" + std::to_string(index) + ": " + row_value;
}

void CommandList::edit_cmd() {
  std::system((this->config->editor + " keys.txt").c_str());
  this->keylist->refresh_keys();
}

void CommandList::help_cmd() {
  logger::print("--------");
  logger::print("'edit' - opens the keyfile in the configured text editor");
  logger::print("'help' - view this command list");
  logger::print("'config' - open the settings");
  logger::print("'exit' - close to program");
  logger::print("'quit' - close to program");
}

void CommandList::config_cmd(bool print_header) {
  if(print_header) {
    logger::print("--------");
    logger::print("Config options:");
    logger::print("'editor' - set the editor you want to use for editing the keyfile");
    logger::print("'symbol' - change symbol displayed before your input");
    logger::print("Type the name of a setting to change or 'exit' to return to the main view");
  }

  std::cout << this->config->symbol << " ";
  std::string input = "";
  std::cin >> input;

  if(input == "exit")
    return;

  std::string* setting_to_change = nullptr;

  if(input == "editor") {
    setting_to_change = &this->config->editor;
    logger::print("Current editor: " + *setting_to_change);
  }
  else if(input == "symbol") {
    setting_to_change = &this->config->symbol;
    logger::print("Current symbol: " + *setting_to_change);
  }
  else {
    logger::print("Invalid setting");
    config_cmd(false);
  }

  if(input.empty()) {
    logger::print("Empty input");
    config_cmd(false);
  }

  std::cout << this->config->symbol << " ";
  std::cin >> input;

  *setting_to_change = input;
  logger::print("Changed setting to: " + input);
  this->config->write_config_file();
}