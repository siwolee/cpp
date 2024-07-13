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
  std::vector<unsigned int> v(30);
  std::srand(std::time(0));
  for (std::vector<unsigned int>::iterator iter = v.begin(); iter != v.end();
       iter++) {
    *iter = std::rand() % 30;
  }

  print_all_list("Before:", v);
  std::cout << "------------------sorted?" << std::endl;
  // merge_insert_sort(v);
  // print_all_list("After:", v);

  PmergeMe pmerge;
  std::vector<unsigned int> _res = pmerge.sorted(v);

  std::sort(v.begin(), v.end());
  for (unsigned int i = 0; i < v.size(); ++i) {
    if (v[i] != _res[i]) {
      std::cout << "failed\n";
      return 1;
    }
  }
  std::cout << "success\n";
  return 0;
}