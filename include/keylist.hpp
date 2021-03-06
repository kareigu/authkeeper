#pragma once
#include <string>

struct Keylist {
  std::string* keys = new std::string[300];

  Keylist();
  ~Keylist();

  void refresh_keys();
};