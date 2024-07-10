#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<unsigned int>& arr) : _arr(arr) {
  _size = arr.size();
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _arr(other._arr) {
  _size = other._size;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    _arr = other._arr;
    _size = other._size;
  }
  return *this;
}

void PmergeMe::_swap(size_t front, size_t back, size_t size) {
  while (size-- > 0) {
    std::swap(_arr[front--], _arr[back--]);
  }
}

bool PmergeMe::comp(unsigned int a, unsigned int b) { return a < b; }

void PmergeMe::_print_all_list(const std::string& preText,
                               const std::vector<unsigned int>& arr) {
  std::cout << preText;
  for (std::vector<unsigned int>::const_iterator it = arr.begin();
       it != arr.end(); ++it) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
}

const size_t PmergeMe::_jacobstal[33] = {
    1u,          3u,         5u,        11u,        21u,        43u,
    85u,         171u,       341u,      683u,       1365u,      2731u,
    5461u,       10923u,     21845u,    43691u,     87381u,     174763u,
    349525u,     699051u,    1398101u,  2796203u,   5592405u,   11184811u,
    22369621u,   44739243u,  89478485u, 178956971u, 357913941u, 715827883u,
    1431655765u, 2863311531u};

void PmergeMe::_insert(size_t rank, size_t target_idx, size_t curr_idx) {
  size_t curr = 0;
  while (curr < rank) {
    unsigned int temp = _arr[curr_idx - curr];
    _arr.erase(_arr.begin() + curr_idx - curr);
    _arr.insert(_arr.begin() + target_idx - curr, temp);
    curr++;
  }
}

// start from 1
size_t _sub_idx(size_t rank, size_t i) { return (rank - 1 + rank * 2 * i); };
size_t _main_idx(size_t rank, size_t i) {
  return (rank * 2 - 1 + rank * 2 * i);
};

// size_t pos_to_idx(size_t rank, size_t pos) { return (); }

void PmergeMe::merge_insert_sort(size_t rank) {
  std::vector<unsigned int> main_seq;
  std::vector<unsigned int> sub_seq;
  size_t seq_len = _size / rank;

  for (size_t front = rank - 1; front + rank < _size; front += 2 * rank) {
    size_t back = front + rank;
    if (_arr[back] < _arr[front]) {
      _swap(front, back, rank);
    }
    sub_seq.push_back(_arr[front]);
    main_seq.push_back(_arr[back]);
  }
  _print_all_list("test:: ", _arr);

  if (seq_len >= 2) {
    merge_insert_sort(rank * 2);
  } else {
    return;
  }

  // if (_size % 2) {
  //   sub_seq.push_back(_arr[_size - 1]);
  // }

  std::vector<unsigned int> sorted_seq;  // to save sorted

  int j = 1;
  size_t compareSize = 4;
  sorted_seq.push_back(sub_seq[0]);   // sorted init ::first sub_seq
  sorted_seq.push_back(main_seq[0]);  // sorted init ::second sub_seq
  seq_len = sub_seq.size();

  while (_jacobstal[j] < seq_len) {
    size_t end = 0;
    // 해당 야곱스탈 수의 인덱스부터 다음 야곱스탈 수의 인덱스까지
    // sorted에 미리 넣어둠
    // end는 insert할 첫 위치로도 사용
    for (end = _jacobstal[j];
         end < _jacobstal[j + 1] && _size >= main_seq.size(); end++) {
      sorted_seq.push_back(main_seq[end - 1]);
    }

    if (end < sub_seq.size()) end++;  // 홀수로 sub_seq가 남았을 때

    // 다음 야곱스탈 수 or sub_seq의 끝에서부터 idx를 줄이며 sorted에 insert
    for (size_t curr = end; curr > _jacobstal[j]; curr--) {
      std::vector<unsigned int>::iterator pos = std::lower_bound(
          sorted_seq.begin(), sorted_seq.begin() + (compareSize - 2),
          sub_seq[curr]);
      size_t dist = std::distance(sorted_seq.begin(), pos);
      sorted_seq.insert(pos, sub_seq[curr]);
      // 실제 _arr에 반영
      _insert(rank, dist * rank, curr * rank);
    }
    j++;
    compareSize *= 2;
  }
}
