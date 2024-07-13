#include "PmergeMe.hpp"

#define ipair std::pair<unsigned int, unsigned int>

template <typename Container,
          typename ContainerPair = std::pair<unsigned int, Container>>
Container merge_insert_sort(Container& v) {
  ContainerPair pair_seq(v.size());

  // init
  for (size_t i = 0; i < v.size(); i++) {
    pair_seq[i] = std::pair<unsigned int, Container>(v[i], Container(1));
    pair_seq[i].second[0] = v[i];
  }
  ContainerPair sorted = _recv_sort(pair_seq);
}

template <typename Container, typename ContainerPair>
Container _recv_sort(ContainerPair& v) {
  // 1. main, sub로 나누기
  typename ContainerPair pair_seq = _make_pair(v);
  // 2. 재귀를 통해 정렬
  ContainerPair sorted_main = _recv_sort(pair_seq);
  Container sorted_sub = reorder_sub_by_main_seq(pair, sorted_main);
  _insert(sorted_vec);
  return sorted_vec;
}

template <typename Container, typename ContainerPair>
Container _make_pair(ContainerPair& v) {
  size_t seq_size = v.size() / 2;
  ContainerPair main(seq_size);
  ContainerPair sub(seq_size + (v % 2));
  for (size_t i = 0; i < seq_size; i++) {
    main[i] = std::Pair(i, v[i]);
    // 더 큰 수를 main에 넣어준다
    // first느 index, second는 value
    if (v[i] > v[i + 1]) {
      main[i] = std::Pair(i, v[i]);
      sub[i] = std::pair(i, v[i + 1]);

    } else {
      main[i] = std::pair(i, v[i + 1]);
      sub[i] = std::Pair(i, v[i]);
    }
  }
  if (seq_size % 2 != 0) {
    sub[seq_size] = std::pair(seq_size, v[v.size() - 1]);
  }
  return (std::pair<Container, Container>(main, sub));
}