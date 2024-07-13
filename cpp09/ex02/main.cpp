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

int main(int ac, char **av) {
  if (ac < 2) {
    std::cout << "try: ./Pmergeme [int1] [int2] [int3] ..." << std::endl;
    return 1;
  }
  std::vector<unsigned int> vec(ac - 1);
  std::deque<unsigned int> deq(ac - 1);
  for (int i = 1; i < ac; i++) {
    // before sorted
    std::cout << av[i] << ", ";
    try {
      vec[i - 1] = std::atoi(av[i]);
      deq[i - 1] = std::atoi(av[i]);
    } catch (std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
      return 1;
    }
  }

  // std::vector<unsigned int> v(30);
  // std::srand(std::time(0));
  // for (std::vector<unsigned int>::iterator iter = v.begin(); iter != v.end();
  //      iter++) {
  //   *iter = std::rand() % 30;
  // }

  // print_all_list("Before:", v);
  // std::cout << "------------------sorted?" << std::endl;

  // PmergeMe pmerge;
  // std::vector<unsigned int> _res = pmerge.sorted(v);

  // std::sort(v.begin(), v.end());
  // print_all_list("_st:", v);
  // for (unsigned int i = 0; i < v.size(); ++i) {
  //   if (v[i] != _res[i]) {
  //     std::cout << "failed\n";
  //     return 1;
  //   }
  // }
  // std::cout << "success\n";
  return 0;
}