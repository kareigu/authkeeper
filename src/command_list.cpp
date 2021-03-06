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
  return this->keylist->keys[index];
}

void CommandList::edit_cmd() {
  std::system((this->config->editor + " keys.txt").c_str());
}