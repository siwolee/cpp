#include "PmergeMe.hpp"

template <typename Container>
void print_all_list(Container arr) {
  for (typename Container::iterator it = arr.begin(); it != arr.end(); it++) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
}
template <typename T>
void _swap(std::vector<T>& arr, size_t front, size_t back, size_t size) {
  while (size-- > 0) {
    T temp = arr[front];
    arr[front] = arr[back];
    arr[back] = temp;
    front--;
    back--;
  }
}

/* curr: main_seq 인덱스, 삽입할 쌍의 마지막 인덱스
 * target: main_seq 인덱스, 목표 위치에 있는 쌍의 마지막 인덱스
 * size: 삽입할 쌍의 크기
 */
template <typename T>
void _insert(std::vector<T>& arr, size_t curr, size_t target, size_t size) {
  std::vector<T> temp_a(size);
  std::vector<T> temp_b(size);
  size_t i = 0;
  for (size_t idx = target - size + 1; idx <= target; idx++) {
    temp_a[i] = arr[idx];
    arr[idx] = arr[curr - size + 1 + i];
    if (i < size - 1) {
      i += 1;
    } else {
      i = 0;
    }
  }
  for (size_t idx = target + 1; idx <= curr; idx++) {
    temp_b[i] = arr[idx];
    arr[idx] = temp_a[i];
    temp_a[i] = temp_b[i];
    if (i < size - 1) {
      i++;
    } else {
      i = 0;
    }
  }
}

template <typename T>
size_t _divideConquer(std::vector<T>& arr, std::vector<size_t> main_seq,
                      size_t idx) {
  size_t left = 0;
  size_t right = idx - 1;
  size_t mid = (left + right) / 2;
  T res = 0;
  while (left < right) {
    mid = (left + right) / 2;
    res = arr[main_seq[idx]] - arr[main_seq[mid]];
    if (res > 0) {  // mid < idx
      left = mid + 1;
    } else if (res < 0) {  // mid > idx
      right = mid;
    } else {
      return mid + 1;
    }
  }
  if (arr[main_seq[idx]] > arr[main_seq[right]]) {
    return idx;
  } else if (arr[main_seq[idx]] > arr[main_seq[mid]]) {
    return right;
  } else if (arr[main_seq[idx]] > arr[main_seq[left]]) {
    return mid;
  } else {
    return left;
  }
}

template <typename T>
void merge_insert_sort(std::vector<T>& arr, size_t rank) {
  std::vector<size_t> main_seq;

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
template void print_all_list<std::vector<int> >(std::vector<int> arr);
template void merge_insert_sort<int>(std::vector<int>& arr, size_t rank);