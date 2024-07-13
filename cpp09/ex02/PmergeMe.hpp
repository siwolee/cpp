#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>
#include <time.h>



bool _comp(const unsigned int &a, const unsigned int &b){ return a < b; }
double ustime(clock_t x) { return (((double)x * 1000) / CLOCKS_PER_SEC);}

template <typename C, typename CC>
class PmergeMe {
 public:
  PmergeMe(C& origin);
  ~PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  C run(std::string type);

 private:
  void _merge_insert_sort(size_t rank);
  void _pair_init(size_t rank);
  void _swap(size_t front, size_t back, size_t rank);
  typename C::iterator _make_elem(typename C::iterator it, C& child, size_t rank);
  void _make_seq(C& main, C& sub, CC& main_rest, CC& sub_rest, size_t seq_len, unsigned int is_odd, size_t rank);
  void _decompose(CC& main, size_t rank);
  void _sort(C& main, C& sub, CC & main_rest, CC& sub_rest);

  void _print_all_list();
  static const size_t _jacobstal[33];

  C& _ref;
  size_t _size;

  void _insert(size_t rank, size_t target_idx, size_t curr_idx);
};

template <typename C, typename CC>
const size_t PmergeMe<C, CC>::_jacobstal[33] = {
  0u, 1u, 3u, 5u, 11u, 21u, 43u, 85u, 171u, 341u,
  683u, 1365u, 2731u, 5461u, 10923u, 21845u, 43691u,
  87381u, 174763u, 349525u, 699051u, 1398101u, 2796203u,
  5592405u, 11184811u, 22369621u, 44739243u, 89478485u,
  178956971u, 357913941u, 715827883u, 1431655765u, 2863311531u
};

template <typename C, typename CC>
PmergeMe<C, CC>::PmergeMe(C& origin) : _ref(origin) {
  _size = origin.size();
}

template <typename C, typename CC>
PmergeMe<C, CC>::~PmergeMe() {}

template <typename C, typename CC>
PmergeMe<C, CC>::PmergeMe(const PmergeMe& other) : _ref(other._ref) {
  _size = other._size;
}

template <typename C, typename CC>
PmergeMe<C, CC>& PmergeMe<C, CC>::operator=(const PmergeMe& other) {
  if (this != &other) {
    _ref = other._ref;
    _size = other._size;
  }
  return *this;
}

template <typename C, typename CC>
C PmergeMe<C, CC>::run(std::string type) {
  clock_t start = clock();
  _merge_insert_sort(1);
  clock_t end = clock();
    
  std::cout << "Time to process a range of " << _size <<" elements with std::"<< type << " : " << ustime(end - start) << " us" << std::endl;

  return _ref;
}

template <typename C, typename CC>
void PmergeMe<C, CC>::_merge_insert_sort(size_t rank) {
  size_t all_len = _size / rank;
  size_t seq_len = all_len / 2;
  if (all_len < 2) return;
  unsigned int is_odd = (all_len % 2);
  _pair_init(rank);

  // _print_all_list();
  _merge_insert_sort(rank * 2);
  if (all_len == 2) return;

  C main(seq_len);
  CC main_rest(seq_len);
  C sub(seq_len + is_odd);
  CC sub_rest(seq_len + is_odd);

  _make_seq(main, sub, main_rest, sub_rest, seq_len, is_odd, rank);

  _sort(main, sub, main_rest, sub_rest);

  _decompose(main_rest, rank);
}

template <typename C, typename CC>
void PmergeMe<C, CC>::_decompose(CC& main, size_t rank) {
  size_t s = 0;
  size_t r = 0;
  for (size_t i = 0; i < _size; i++) {
    if (r >= rank) {
      r = 0;
      s++;
    }
    if (s >= main.size()) return ;
    _ref[i] = main[s][r];
    r++;
  }
}

template <typename C, typename CC>
void PmergeMe<C, CC>::_sort(C& main, C& sub, CC & main_rest, CC& sub_rest) {
  size_t j_idx = 1;
  size_t sub_len = sub.size();
  size_t curr;
  typename C::iterator pos;
  size_t range;

  main.insert(main.begin(), sub[0]);
  main_rest.insert(main_rest.begin(), sub_rest[0]);
  // std::cout <<"-----" << sub_len << "-----" <<std::endl;//DEBUG

  while (1) {
    range = _jacobstal[j_idx + 1] + _jacobstal[j_idx] - 1;
    if (range > main.size()) range = main.size(); 
    
    if (_jacobstal[j_idx + 1] > sub_len ) curr = sub_len -1; 
    else curr = _jacobstal[j_idx + 1] - 1;
    
    for (; curr >= _jacobstal[j_idx]; curr--) {
      // std::cout<< curr + 1 <<std::endl; //DEBUG
      pos = std::lower_bound(main.begin(), main.begin() + range, sub[curr], _comp);
      if (std::distance(main.begin(), pos) > (long)range)  {
        main_rest.push_back(sub_rest[curr]);
        main.push_back(sub[curr]);
      }
      main_rest.insert(main_rest.begin() + std::distance(main.begin(), pos), sub_rest[curr]);
      main.insert(pos, sub[curr]);
    }
    if (_jacobstal[j_idx + 1] > sub_len) break ;
    j_idx++;
  }
}

template <typename C, typename CC>
void PmergeMe<C, CC>::_make_seq(C& main, C& sub, CC& main_rest, CC& sub_rest, size_t seq_len, unsigned int is_odd, size_t rank) {
  typename C::iterator it = _ref.begin();
  
  for (size_t i = 0; i < seq_len; i++) {
    sub_rest[i] = C(rank);
    it = _make_elem(it, sub_rest[i], rank);
    sub[i] = sub_rest[i][rank - 1];

    main_rest[i] = C(rank);
    it = _make_elem(it, main_rest[i], rank);
    main[i] = main_rest[i][rank - 1];
  }
  if (is_odd) {
    sub_rest[seq_len] = C(rank);
    size_t e = 0;
    for (; e < rank; e++) {
    sub_rest[seq_len][e] = *it;
    it++;
    if (it == _ref.end()) {
      e++;
      break;
    }
    }
    sub[seq_len] = sub_rest[seq_len][e - 1];
  }
}

template <typename C, typename CC>
typename C::iterator PmergeMe<C, CC>::_make_elem(typename C::iterator it, C& child, size_t rank) {
  for (size_t e = 0; e < rank; e++) {
    child[e] = *it;
    it++;
  }
  return it;
}

template <typename C, typename CC>
void PmergeMe<C, CC>::_pair_init(size_t rank) {
  for (size_t front = rank - 1; front + rank < _size; front += 2 * rank) {
    size_t back = front + rank;
    if (_ref[back] < _ref[front]) {
      _swap(front, back, rank);
    }
  }
}

template <typename C, typename CC>
void PmergeMe<C, CC>::_swap(size_t front, size_t back, size_t size) {
  while (size-- > 0) {
    std::swap(_ref[front--], _ref[back--]);
  }
}

template <typename C, typename CC>
void PmergeMe<C, CC>::_print_all_list() {
  for (typename C::const_iterator it = _ref.begin(); it != _ref.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

#endif  // PMERGEME_HPP
