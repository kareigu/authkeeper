#pragma once
#include <string>

struct Config {
  std::string editor = "vim";
  std::string symbol = "$";

  Config();
  ~Config();  

  void write_config_file();

  private:
    void assign_config_values(std::string (*config)[2]);
};