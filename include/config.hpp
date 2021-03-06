#pragma once
#include <string>

struct Config {
  std::string editor = "vim";

  Config();
  ~Config();  

  private:
    void assign_config_values(std::string (*config)[2]);
};