#pragma once
#include <string>
#include "logger.hpp"
#include "keylist.hpp"

struct CommandList {
  Keylist* keylist;


  CommandList(Keylist* keylist);
  ~CommandList();

  //*
  //* Commands
  //*
  void exit_cmd();
  std::string loadkey_cmd(int index);
  void edit_cmd();
};

