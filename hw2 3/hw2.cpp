#include "hw2functions.h"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }

  std::ifstream input_file(argv[1]);

  if (!input_file) {
    std::cerr << "Error: could not open input file: " << argv[1] << std::endl;
    return 1;
  }

  int freq[26] = {0};
  char c;

  while (input_file.get(c)) {
    if (is_alpha(c)) {
      update_freq(c, freq);
    }
  }

  print_most_freq(freq);
  print_least_freq(freq);
  std::cout << std::endl;
  print_freq_list(freq);
  std::cout << std::endl; 
  print_bar_chart(freq);

  return 0;
}