#include <time.h>

#include <iostream>

#include "PmergeMe.hpp"

template <typename Container>
void print_all_list(std::string preText, Container arr) {
  std::cout << preText;
  for (typename Container::iterator it = arr.begin(); it != arr.end(); it++) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<unsigned int> v(10);
  std::srand(std::time(0));
  for (std::vector<unsigned int>::iterator iter = v.begin(); iter != v.end();
       iter++) {
    *iter = std::rand() % 30;
  }

  print_all_list("Before:", v);
  std::cout << "------------------sorted?" << std::endl;
  // merge_insert_sort(v);
  PmergeMe pm(v);
  pm.merge_insert_sort(1);
  print_all_list("After:", v);
}