#include "config.hpp"
#include <fstream>
#include <string>
#include "logger.hpp"

const int CONFIG_LINE_COUNT = 2;

std::string* read_config_file() {
  std::ifstream inputStream("authkeeper.conf");
  std::string* lines = new std::string[CONFIG_LINE_COUNT];
  
  if(inputStream.is_open()) {
    for(int i = 0; i < CONFIG_LINE_COUNT; i++) {
      std::getline(inputStream, lines[i]);
    }

    inputStream.close();
  }

  return lines;
}

void split_config_lines(std::string* config_lines, std::string (*config)[2]) {

  for(int i = 0; i < CONFIG_LINE_COUNT; i++) {
    std::string full_line = config_lines[i];
    int split_point = full_line.find_first_of("=");
    std::string setting = "";
    std::string value = "";
    
    for(int j = 0; j < split_point; j++) {
      setting += full_line[j];
    }

    for(int j = split_point + 1; (long unsigned int)j < full_line.length(); j++) {
      value += full_line[j];
    }

    config[i][0] = setting;
    config[i][1] = value;
  }

  delete[] config_lines;
}

void Config::assign_config_values(std::string (*config)[2]) {
  for(int i = 0; i < CONFIG_LINE_COUNT; i++) {
    if(!config[i][1].empty()) {
      std::string curr = config[i][0];
      if(curr == "EDITOR")
        this->editor = config[i][1];
      else if(curr == "SYMBOL")
        this->symbol = config[i][1];
    }
  }
  
  delete[] config;
}



Config::Config() {
  std::string* config_lines = read_config_file();
  auto config = new std::string[CONFIG_LINE_COUNT][2];
  split_config_lines(config_lines, config);
  assign_config_values(config);
}

Config::~Config() {

}