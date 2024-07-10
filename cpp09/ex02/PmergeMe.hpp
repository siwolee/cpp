#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

// unsigned intemplate class definition
class PmergeMe {
 public:
  PmergeMe(std::vector<unsigned int>& arr);
  ~PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  void merge_insert_sort(size_t rank);

 private:
  void _swap(size_t front, size_t back, size_t size);
  static bool comp(unsigned int a, unsigned int b);
  static void _print_all_list(const std::string& preText,
                              const std::vector<unsigned int>& arr);
  static const size_t _jacobstal[33];

  std::vector<unsigned int>& _arr;
  size_t _size;

  void _insert(size_t rank, size_t target_idx, size_t curr_idx);
};

#endif  // PMERGEME_HPP