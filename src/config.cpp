#include "config.hpp"
#include <fstream>
#include <string>
#include <filesystem>
#include "logger.hpp"

const int CONFIG_LINE_COUNT = 2;
const std::string CONFIG_FILE_NAME = "authkeeper.conf";

std::string* read_config_file() {
  std::ifstream inputStream(CONFIG_FILE_NAME);
  std::string* lines = new std::string[CONFIG_LINE_COUNT];
  
  if(inputStream.is_open()) {
    for(int i = 0; i < CONFIG_LINE_COUNT; i++) {
      std::getline(inputStream, lines[i]);
    }

    inputStream.close();
  }

  return lines;
}

void Config::write_config_file() {
  std::ofstream outputStream(CONFIG_FILE_NAME);
  
  if(outputStream.is_open()) {
    outputStream << "EDITOR=" << this->editor << std::endl;
    outputStream << "SYMBOL=" << this->symbol << std::endl;

    outputStream.close();
  }
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
  if(std::filesystem::exists(CONFIG_FILE_NAME)) {
    std::string* config_lines = read_config_file();
    auto config = new std::string[CONFIG_LINE_COUNT][2];
    split_config_lines(config_lines, config);
    assign_config_values(config);
  } else {
    write_config_file();
  }
}

Config::~Config() {

}