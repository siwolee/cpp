#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

// unsigned intemplate class definition
class PmergeMe {
 public:
  static void merge_insert_sort(std::vector<unsigned int>& arr, size_t rank);
  static void merge_insert_sort(std::deque<unsigned int>& arr, size_t rank);

 private:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);

  static void _swap(std::vector<unsigned int>& arr, size_t front, size_t back,
                    size_t size);
  static size_t _divideConquer(std::vector<unsigned int>& arr,
                               std::vector<size_t> main_seq, size_t idx);
  static void _insert(std::vector<unsigned int>& arr, size_t curr,
                      size_t target, size_t size);
};

#endif  // PMERGEME_HPP