#include "PmergeMe.hpp"

void PmergeMe::_swap(std::vector<unsigned int>& arr, size_t front, size_t back,
                     size_t size) {
  while (size-- > 0) {
    std::swap(arr[front--], arr[back--]);
  }
}

void PmergeMe::_insert(std::vector<unsigned int>& arr, size_t curr,
                       size_t target, size_t size) {
  std::vector<unsigned int> temp(arr.begin() + curr - size + 1,
                                 arr.begin() + curr + 1);
  arr.erase(arr.begin() + curr - size + 1, arr.begin() + curr + 1);

  arr.insert(arr.begin() + target - size + 1, temp.begin(), temp.end());
}

size_t PmergeMe::_divideConquer(std::vector<unsigned int>& arr,
                                std::vector<size_t> main_seq, size_t idx) {
  size_t left = 0;
  size_t right = idx - 1;
  size_t mid = (left + right) / 2;
  while (left < right) {
    mid = (left + right) / 2;
    if (arr[main_seq[idx]] > arr[main_seq[mid]]) {  // mid < idx
      left = mid + 1;
    } else if (arr[main_seq[idx]] < arr[main_seq[mid]]) {  // mid > idx
      right = mid;
    } else {
      return mid + 1;
    }
  }
  if (arr[main_seq[idx]] > arr[main_seq[right]]) {
    return idx;
  } else {
    return left;
  }
}

void PmergeMe::merge_insert_sort(std::vector<unsigned int>& arr, size_t rank) {
  std::vector<size_t> main_seq;

  // if (rank == 1) {
  //   _arr = arr;
  //   arr_size = arr.size();
  // }

  // check if the array is odd
  bool is_odd = false;
  if (arr.size() % 2) {
    is_odd = true;
  }
  // get main(winner) sequence
  // swap the elements - winner goes for last
  for (size_t front = rank - 1; front + rank < arr.size(); front += 2 * rank) {
    size_t back = front + rank;
    if (arr[back] < arr[front]) {
      _swap(arr, front, back, rank);
    }
    main_seq.push_back(front);
    main_seq.push_back(back);
  }
  // recv for winner sequence
  if (main_seq.size() > 2) {
    merge_insert_sort(arr, rank * 2);
  }

  // add the last element if the array is odd
  if (is_odd) {
    main_seq.push_back(arr.size() - 1);
  }

  // merge the two sequences by divide / insert
  for (size_t idx = 2; idx < main_seq.size(); idx++) {
    size_t pos = _divideConquer(arr, main_seq, idx);
    if (pos < idx) _insert(arr, main_seq[idx], main_seq[pos], rank);
  }
}
// Explicit template instantiation
// template void print_all_list<std::vector<unsigned int><int>
// >(std::vector<unsigned int><int> arr); template void
// merge_insert_sort<int>(std::vector<unsigned int><int>& arr, size_t rank);

PmergeMe::PmergeMe(){};

PmergeMe::~PmergeMe(){};

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; };

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  (void)other;
  return *this;
};