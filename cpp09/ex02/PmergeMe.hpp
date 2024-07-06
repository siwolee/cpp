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
  void merge_insert_sort(size_t rank);
  void merge_insert_sort(std::deque<unsigned int>& arr, size_t rank);

  PmergeMe(std::vector<unsigned int>& arr);
  ~PmergeMe();

 private:
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);

  void _swap(size_t front, size_t back, size_t size);
  // size_t _divideConquer(std::vector<size_t> main_seq, size_t idx, size_t
  // right); void _insert(size_t curr, size_t target, size_t size);

  std::vector<unsigned int>& _arr;
  size_t _size;
  static const size_t _jacobstal[33];
  static size_t _j_idx(size_t i);
};

#endif  // PMERGEME_HPP