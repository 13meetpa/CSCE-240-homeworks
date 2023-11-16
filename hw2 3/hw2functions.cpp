#include "hw2functions.h"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
bool is_alpha(char c) {
  return (std::isalpha(c) != 0);
}

char to_lower(char c) {
  return std::tolower(c);
}

void update_freq(char c, int* freq) {
  if (is_alpha(c)) {
    freq[to_lower(c) - 'a']++;
  } else if (std::isspace(c)) {
    freq[26]++; 
  }
}



void print_most_freq(int* freq) {
  int max_freq = *std::max_element(freq, freq + 26);

  std::cout << "Highest frequency character";
  if (max_freq > 1) {
    std::cout << " ";
  }
  std::cout << "(appeared " << max_freq << " time";
  if (max_freq > 1) {
    std::cout << "s ";
  }
  std::cout << "in the file): ";

  bool first_char = true;
  for (int i = 0; i < 26; i++) {
    if (freq[i] == max_freq) {
      if (!first_char) {
        std::cout << ", ";
      }
      std::cout << (char)('a' + i);
      first_char = false;
    }
  }
  std::cout << std::endl;
}

void print_least_freq(int* freq) {
  int min_freq = -1;
  for (int i = 0; i < 26; i++) {
    if (freq[i] >= 0 && (min_freq == -1 || freq[i] < min_freq)) {
      min_freq = freq[i];
    }
  }

  std::cout << "Lowest frequency characters";
  if (min_freq > 1) {
    std::cout << "s";
  }
  std::cout << " (appeared " << min_freq << " times";
  if (min_freq > 1) {
    std::cout << "s";
  }
  std::cout << " in the file): ";
  int temp_array[26];
  int inc = 0;
  for (int i = 0; i < 26; i++) {
    if (freq[i] == min_freq) {
      temp_array[inc] = i;
      inc++;
    }
  }
  for (int i = 0; i < inc; i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    if (i == inc - 1) {
      std::cout << "and ";
    }
    std::cout << (char)('a' + temp_array[i]);
  }
  std::cout << std::endl;
}

void print_freq_list(int* freq) {
  char char_array[26];
  int freq_array[26];
  int num_chars = 0;
  for (int i = 0; i < 26; i++) {
    if (freq[i] >= 0) {
      char_array[num_chars] = 'a' + i;
      freq_array[num_chars] = freq[i];
      num_chars++;
    }
  }

  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (int i = 0; i < num_chars - 1; i++) {
      if (freq_array[i] < freq_array[i + 1] || (freq_array[i] == freq_array[i + 1] && char_array[i] > char_array[i + 1])) {
        std::swap(freq_array[i], freq_array[i + 1]);
        std::swap(char_array[i], char_array[i + 1]);
        swapped = true;
      }
    }
  }

  for (int i = 0; i < 26; i++) {
    std::cout << char_array[i] << ": " << freq_array[i] << std::endl;
  }
}
void print_bar_chart(int* freq) {
  int max_freq = *std::max_element(freq, freq + 26);
  for (int i = max_freq; i > 0; i--) {
    std::cout << std::setw(2) << i << " ";
    for (int j = 0; j < 26; j++) {
      if (freq[j] >= i) {
        std::cout << "* ";
      } else {
        std::cout << "  ";
      }
    }
    std::cout << std::endl;
  }

  std::cout << "   ";
  for (int i = 0; i < 26; i++) {
    std::cout << (char)('a' + i) << " ";
  }
  std::cout << std::endl;
}





