#include "command_list.hpp"
#include "logger.hpp"
#include "keylist.hpp"

CommandList::CommandList(Keylist* keylist) {
  this->keylist = keylist;
}

CommandList::~CommandList() {
  delete this->keylist;
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
  std::system("vim keys.txt");
}