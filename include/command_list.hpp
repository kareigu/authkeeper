#pragma once
#include <string>
#include "logger.hpp"
#include "keylist.hpp"
#include "config.hpp"

struct CommandList {
  Keylist* keylist;
  Config* config;


  CommandList(Keylist* keylist, Config* config);
  ~CommandList();

  //*
  //* Commands
  //*
  void exit_cmd();
  std::string loadkey_cmd(int index);
  void edit_cmd();
};

