#pragma once

namespace logger {
  void print(std::string in);

  template<typename T>
  void debug(T in, std::string field = "val", bool spacing = false) {
    if(spacing) 
      std::cout << "--------------" << std::endl;

    std::cout << field << ": " << in << std::endl;
  }

  void printArr(int *in, int len);
}
