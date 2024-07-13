#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

template <typename Container>
class PmergeMe {
 public:
  PmergeMe() {}
  ~PmergeMe() {}
  Container<unsigned int> merge_insert_sort(Container<unsigned int>& v);

 private:
  unsigned int find_pair(std::vector<ipair>& pairs, unsigned int v);
  void print_vec(std::vector<unsigned int>& v);
  vpair set_pair(std::vector<unsigned int>& v);
  std::vector<unsigned int> insertion(std::vector<unsigned int>& cv,
                                      std::vector<unsigned int> sv,
                                      unsigned int idx);
};