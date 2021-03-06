#include "config.hpp"
#include <fstream>
#include <string>
#include "logger.hpp"

int CONFIG_LINE_COUNT = 2;

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

std::string* split_config_lines(std::string* config_lines) {
  for(int i = 0; i < CONFIG_LINE_COUNT; i++) {
    std::string full_line = config_lines[i];
    int split_point = full_line.find_first_of("=");
    char* setting = new char[split_point];
    
    for(int j = 0; j < split_point; i++) {
      setting[j] = full_line[j];
    }

    logger::print(setting);
  }

  std::string* rtr = new std::string("yes");

  return rtr;
}

/* void assign_config_values(std::string* config_lines) {
  for(int i = 0; i < CONFIG_LINE_COUNT; i++) {
    std::string curr = config_lines[i].

    if(curr == "")
  }
} */



Config::Config() {
  std::string* config_lines = read_config_file();
  std::string* config = split_config_lines(config_lines);
  logger::print(*config);
}

Config::~Config() {

}