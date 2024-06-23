#include <time.h>

#include <iostream>

#include "MergeSort.hpp"

int main() {
  std::vector<int> v(10);
  std::srand(std::time(0));
  for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
    *iter = std::rand();
  }
  for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
    std::cout << *iter << std::endl;
  }

  std::cout << "------------------sorted?" << std::endl;
  merge_sort(v);
  for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
    std::cout << *iter << std::endl;
  }
}