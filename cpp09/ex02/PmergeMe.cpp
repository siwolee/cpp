#include "PmergeMe.hpp"

void PmergeMe::_swap(size_t front, size_t back, size_t size) {
  while (size-- > 0) {
    std::swap(_arr[front--], _arr[back--]);
  }
}

void PmergeMe::_insert(size_t curr, size_t target, size_t size) {
  std::vector<unsigned int> temp(_arr.begin() + curr - size + 1,
                                 _arr.begin() + curr + 1);
  _arr.erase(_arr.begin() + curr - size + 1, _arr.begin() + curr + 1);

  _arr.insert(_arr.begin() + target - size + 1, temp.begin(), temp.end());
}

size_t PmergeMe::_divideConquer(std::vector<size_t> main_seq, size_t idx) {
  size_t left = 0;
  size_t right = idx - 1;
  size_t mid = (left + right) / 2;
  std::cout << "idx: " << main_seq[idx] << " right: " << main_seq[right]
            << std::endl;
  while (left < right) {
    mid = (left + right) / 2;
    if (_arr[main_seq[idx]] > _arr[main_seq[mid]]) {  // mid < idx
      left = mid + 1;
    } else if (_arr[main_seq[idx]] < _arr[main_seq[mid]]) {  // mid > idx
      right = mid;
    } else {
      return mid + 1;
    }
  }
  if (_arr[main_seq[idx]] > _arr[main_seq[right]]) {
    return idx;
  } else {
    return left;
  }
}

void PmergeMe::merge_insert_sort(size_t rank) {
  std::vector<size_t> main_seq;

  // check if the _array is odd
  bool is_odd = false;
  if (_size % 2) {
    is_odd = true;
  }
  // get main(winner) sequence
  // swap the elements - winner goes for last
  for (size_t front = rank - 1; front + rank < _size; front += 2 * rank) {
    size_t back = front + rank;
    if (_arr[back] < _arr[front]) {
      _swap(front, back, rank);
    }
    main_seq.push_back(front);
    main_seq.push_back(back);
  }
  // recv for winner sequence
  if (main_seq.size() > 2) {
    merge_insert_sort(rank * 2);
  }

  // add the last element if the _array is odd
  if (is_odd) {
    main_seq.push_back(_size - 1);
  }

  // merge the two sequences by divide / insert
  for (size_t idx = 2; idx < main_seq.size(); idx++) {
    size_t pos = _divideConquer(main_seq, idx);
    if (pos < idx) _insert(main_seq[idx], main_seq[pos], rank);
  }
}
// Explicit template instantiation
// template void print_all_list<std::vector<unsigned int><int>
// >(std::vector<unsigned int><int> _arr); template void
// merge_insert_sort<int>(std::vector<unsigned int><int>& _arr, size_t rank);

PmergeMe::PmergeMe(std::vector<unsigned int>& _arr) : _arr(_arr) {
  _size = _arr.size();
};

PmergeMe::~PmergeMe(){};

PmergeMe::PmergeMe(const PmergeMe& other) : _arr(other._arr) {
  _size = other._size;
};

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  (void)other;
  return *this;
};

const unsigned long PmergeMe::_jacobstal[32] = {
    3u,         5u,        11u,        21u,        43u,        85u,
    171u,       341u,      683u,       1365u,      2731u,      5461u,
    10923u,     21845u,    43691u,     87381u,     174763u,    349525u,
    699051u,    1398101u,  2796203u,   5592405u,   11184811u,  22369621u,
    44739243u,  89478485u, 178956971u, 357913941u, 715827883u, 1431655765u,
    2863311531u};