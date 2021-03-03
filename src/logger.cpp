#include <iostream>
#include <string>
#include <iterator>

namespace logger {
  void print(std::string in) {
    std::cout << in << std::endl;
  }

  void printArr(int *in, int len) {
    len--;
    std::string out = "[";
    for (int i = 0; i < len; i++) {
      out.append(" " + std::to_string(in[i]) + ",");
    }
    out.append(" " + std::to_string(in[len]));
    out.append(" ]");
    std::cout << out << std::endl;
  }
}
