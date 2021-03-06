#pragma once
#include <string>
#include <fstream>

std::string* load_keylist() {
  std::ifstream inputStream("keys.txt");
  std::string* output = new std::string[300];

  if(inputStream.is_open()) {
    for(int i = 0; i < 300; i++) {
      std::getline(inputStream, output[i]);
    }

    inputStream.close();
  }

  return output;
}
