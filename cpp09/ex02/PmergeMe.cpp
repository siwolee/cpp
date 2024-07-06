#include "PmergeMe.hpp"

size_t main_seq_idx(size_t i, size_t rank) { return (i * rank - 1); };

template <typename Container>
void _print_all_list(std::string preText, Container arr) {
  std::cout << preText;
  for (typename Container::iterator it = arr.begin(); it != arr.end(); it++) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
}

// void _print_all_list_ms(std::string preText, std::vector<unsigned int> arr,
//                         std::vector<unsigned int> ms) {
//   std::cout << "\n" << preText;
//   std::vector<unsigned int>::iterator msit = ms.begin();
//   size_t i = 0;
//   while (msit != ms.end() && i < arr.size()) {
//     if (*msit == i) {
//       std::cout << "[" << *msit << "]";
//       msit++;
//     }
//     std::cout << arr[i] << " ";
//     i++;
//   }
//   std::cout << std::endl;
// }

void PmergeMe::_swap(size_t front, size_t back, size_t size) {
  while (size-- > 0) {
    std::swap(_arr[front--], _arr[back--]);
  }
}

// void PmergeMe::_insert(size_t curr, size_t target, size_t size) {
//   std::vector<unsigned int> temp(_arr.begin() + curr - size + 1,
//                                  _arr.begin() + curr + 1);
//   _arr.erase(_arr.begin() + curr - size + 1, _arr.begin() + curr + 1);

//   _arr.insert(_arr.begin() + target - size + 1, temp.begin(), temp.end());
// }

// size_t PmergeMe::_divideConquer(std::vector<unsigned int> sorted, unsigned
// int value,
//                                 size_t right) {
//   size_t left = 0;
//   size_t mid = right / 2;

//   std::cout << "value : " << value << " left[" << left
//             << "]=" << sorted[left] << " right: [" << right
//             << "]=" << sorted[right] << std::endl;
//   while (left < right) {
//     mid = (left + right) / 2;
//     if (value > sorted[mid]) {  // mid < idx
//       left = mid + 1;
//     } else if (idx < sorted[mid]) {  // mid > idx
//       right = mid;
//     } else {
//       return mid + 1;
//     }
//   }
//   if (value > sorted[right]) {
//     return right + 1;
//   } else {
//     return left;
//   }
// }

void PmergeMe::merge_insert_sort(size_t rank) {
  std::vector<unsigned int> main_seq;
  std::vector<unsigned int> sub_seq;
  std::vector<unsigned int> sorted_seq;
  size_t seq_len = _size / rank;

  // get main(winner) sequence
  // swap the elements - winner goes for last
  for (size_t front = rank - 1; front + rank < _size; front += 2 * rank) {
    size_t back = front + rank;
    if (_arr[back] < _arr[front]) {
      _swap(front, back, rank);
    }
    sub_seq.push_back(_arr[front]);
    main_seq.push_back(_arr[back]);
  }
  _print_all_list("test:: ", _arr);
  // recv for winner sequence

  if (seq_len >= 2) {
    merge_insert_sort(rank * 2);
  } else
    return;

  // add the last element
  //  if the _array is odd
  if (_size % 2) {
    sub_seq.push_back(_size - 1);
  }

  // merge the two sequences by divide / insert
  std::cout << "\nstart rank " << std::to_string(rank) << std::endl;
  _print_all_list("- mainseq:: ", main_seq);
  _print_all_list("- subseq:: ", sub_seq);
  // _print_all_list_ms("before:: ", _arr, main_seq);
  int j = 1;
  size_t x = 0;
  sorted_seq.push_back(main_seq[0]);
  sorted_seq.push_back(sub_seq[0]);  // make sorted list
  seq_len = sub_seq.size();
  // size_t sorted_len;
  while (_j_idx(j) < seq_len) {
    // sorted 갯수 : _jacobstal[j] * 2;
    for (size_t i = _j_idx(j); i < _j_idx(j + 1);
         i++)  // add main seq to sorted list
      sorted_seq.push_back(i * rank);
    // sorted 세팅 끝

    // 다음 야콥스탈 수 확인
    size_t end = _j_idx(j + 1);
    if (seq_len < _j_idx(j + 1)) end = seq_len;
    std::vector<unsigned int>::iterator last_elem = sorted_seq.end() - 1;
    for (size_t curr = end; curr > _j_idx(j); curr--) {
      sorted_seq.insert(
          std::lower_bound(sorted_seq.begin(), last_elem, curr) + 1, curr);
      last_elem--;
    }
    j++;
  }
  _print_all_list("- sorted:: ", sorted_seq);
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

const size_t PmergeMe::_jacobstal[33] = {
    1u,          3u,         5u,        11u,        21u,        43u,
    85u,         171u,       341u,      683u,       1365u,      2731u,
    5461u,       10923u,     21845u,    43691u,     87381u,     174763u,
    349525u,     699051u,    1398101u,  2796203u,   5592405u,   11184811u,
    22369621u,   44739243u,  89478485u, 178956971u, 357913941u, 715827883u,
    1431655765u, 2863311531u};

size_t PmergeMe::_j_idx(size_t i) { return (_jacobstal[i] - 1); }