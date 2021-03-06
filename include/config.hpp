#pragma once
#include <string>

struct Config {
  std::string editor = "vim";

  Config();
  ~Config();  
};