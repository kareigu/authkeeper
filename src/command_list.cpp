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

void CommandList::exit_cmd() {
  logger::print("Exiting");
  exit(0);
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
}