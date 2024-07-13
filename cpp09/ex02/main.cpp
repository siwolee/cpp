#include <time.h>

#include <iostream>
#include <sstream>
#include "PmergeMe.hpp"

#define ivec std::vector<unsigned int>
#define ivpair std::vector<std::vector<unsigned int> >
#define ideq std::deque<unsigned int>
#define idpair std::deque<std::deque<unsigned int> >

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
    std::cout << "try: ./PmergeMe int int int ..." << std::endl;
    return 1;
  }
  ivec vec;
  ideq deq;
  int i = 0;
  while (++i < ac){
    std::string str(av[i]);
    std::stringstream ss(str);
    unsigned int temp;

    while (!ss.eof()) {
      try {
        ss >> temp;
        vec.push_back(temp);
        deq.push_back(temp);
      } catch (std::exception &e) {
        std::cout << "Error"<< std::endl;
        return 1;
      }
    }
  }
  
  ivec sortvec = ivec(vec);
  std::sort(sortvec.begin(), sortvec.end());
  print_all_list("Before:", vec);
  print_all_list("After:", sortvec);

  PmergeMe<ivec, ivpair > pm_vec(vec);
  ivec res_vec = pm_vec.run("vector");
  // std::cout << "vector " << is_sorted(res_vec.begin(), res_vec.end()) <<std::endl;
  PmergeMe<ideq, idpair > pm_deq(deq);
  ideq res_deq = pm_deq.run("deque ");
  // std::cout << "deque  " << is_sorted(res_deq.begin(), res_deq.end()) <<std::endl;

  return 0;
}