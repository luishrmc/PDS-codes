#include <iostream>
#include <vector>

#include "Algoritmos.hpp"

template <class T> void read_input(std::vector<T> &vec) {
  T val;
  while (std::cin >> val) {
    vec.push_back(val);
  }
}

template <class T> void print_input(std::vector<T> &vec) {

  for (auto it = vec.begin();; it++) {

    if (it == vec.end() - 1) {
      std::cout << *it << std::endl;
      break;
    }

    std::cout << *it << ", ";
  }
}

template <class T> T get_max(std::vector<T> &vec) {

  if (vec.empty()) {
    std::cout << "Erro: vetor vazio.\n";
  }

  T max = *vec.begin();

  for (auto it = vec.begin() + 1; it != vec.end(); it++) {

    if (*it > max) {
      max = *it;
    }
  }
  return max;
}

template <class T> unsigned int count_duplicates(std::vector<T> &vec) {

  bool pass;
  int sum = 0;

  for (auto it = vec.begin(); it != vec.end(); it++) {

    pass = false;

    if (it != vec.begin()) {

      for (auto aux2 = vec.begin(); aux2 != it; aux2++) {
        if (*aux2 == *it) {
          pass = true;
          break;
        }
      }
    }

    if (pass == true)
      continue;

    for (auto aux = it + 1; aux != vec.end(); aux++) {
      if (*it == *aux) {
        sum++;
      }
    }
  }

  return sum;
}

template <class T> void test_print_input() {
  std::vector<T> vec;
  read_input(vec);
  print_input(vec);
}

template <class T> void test_get_max() {
  std::vector<T> vec;
  read_input(vec);
  std::cout << get_max(vec) << std::endl;
}

template <class T> void test_count_dups() {
  std::vector<T> vec;
  read_input(vec);
  std::cout << count_duplicates(vec) << std::endl;
}

int main() {
  int tipo_teste;
  std::cin >> tipo_teste;
  switch (tipo_teste) {
  case 0:
    test_print_input<std::string>();
    break;
  case 1:
    test_print_input<int>();
    break;
  case 2:
    test_get_max<double>();
    break;
  case 3:
    test_get_max<char>();
    break;
  case 4:
    test_count_dups<int>();
    break;
  case 5:
    test_count_dups<std::string>();
    break;
  default:
    std::cout << "Erro: teste invalido: " << tipo_teste << std::endl;
  }
  return 0;
}
