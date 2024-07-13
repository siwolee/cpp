#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

#define ipair std::pair<unsigned int, unsigned int>
#define iv std::vector<unsigned int>
#define vpair std::pair<iv, iv>

class PmergeMe {
 public:
  PmergeMe() {}
  ~PmergeMe() {}
  std::vector<unsigned int> sorted(std::vector<unsigned int>& v);

 private:
  unsigned int find_pair(std::vector<ipair>& pairs, unsigned int v);
  void print_vec(std::vector<unsigned int>& v);
  vpair set_pair(std::vector<unsigned int>& v);
  std::vector<unsigned int> insertion(std::vector<unsigned int>& cv,
                                      std::vector<unsigned int> sv,
                                      unsigned int idx);
};