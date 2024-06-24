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
  std::vector<unsigned int> v(50);
  std::srand(std::time(0));
  for (std::vector<unsigned int>::iterator iter = v.begin(); iter != v.end();
       iter++) {
    *iter = std::rand() % 50;
  }

  print_all_list("Before:", v);
  std::cout << "------------------sorted?" << std::endl;
  // merge_insert_sort(v);
  PmergeMe::merge_insert_sort(v, 1);
  print_all_list("After:", v);
}