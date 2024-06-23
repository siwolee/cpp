#include <algorithm>
#include <vector>

getJacobstal() {}

template <typename T>
void _getPos(std::vector<T> &arr, size_t len) {}

template <typename T>
void _insert_merge(std::vector<T> &arr, size_t low, size_t high) {
  std::vector<T> unsorted_arr(high - low);
  size_t length = high - low;

  // 초기화
  for (int i = low; i < high; i++) unsorted_arr.push_back(arr[i]);
  while (length) {
    arr[_getPos(unsorted_arr, length) + low] = unsorted_arr[length];
    length--;
  }
}

template <typename T>
// high - low  == (length)가 최소 2여야 머지 가능
void _divide(std::vector<T> &arr, size_t low, size_t high, size_t depth) {
  if (high - low == 1) return;
  size_t mid = low + (high - low) / 2;
  if ((high - low) > 2) {
    _divide(arr, low, mid, depth + 1);
    _divide(arr, mid, high, depth + 1);
  }
  // _merge(arr, low, high);
  _insert_merge(arr, low, high);
}

template <typename T>
void merge_sort(std::vector<T> &arr) {
  _divide(arr, 0, arr.size(), 0);
}
