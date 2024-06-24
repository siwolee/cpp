#include <time.h>

#include <iostream>

#include "PmergeMe.hpp"

int main() {
  std::vector<int> v(10);
  std::srand(std::time(0));
  for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
    *iter = std::rand() % 20;
  }

  std::cout << "------------------sorted?" << std::endl;
  // merge_insert_sort(v);
  std::cout << "Before:";
  print_all_list(v);
  merge_insert_sort(v, 1);
  std::cout << "After";
  print_all_list(v);
}