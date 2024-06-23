#include <algorithm>
#include <vector>

template <typename T>
void  _swap(std::vector<T> &arr, size_t pos_a, size_t pos_b) {
  T temp;
  temp = arr[pos_a];
  arr[pos_a] = arr[pos_b];
  arr[pos_b] = temp;
}

//calculcate position to get position
//arr is copied array, len is length to calculate and also position of key
//just comparing in order, not binary search
template <typename T>
size_t _getPos(std::vector<T> &arr, size_t len) {
  for (size_t i = 0; i < len ; i++ ){
    if (arr[i] > arr[len]){
      return i;
    }
  }
  return len;
}

template <typename T>
void _insert_merge(std::vector<T> &arr, size_t low, size_t high) {
  
  // 순서 역순으로 계산하면 귀찮아짐
  for (size_t curr_pos = low; curr_pos < high; curr_pos++) {
    size_t pos = _getPos(arr, curr_pos);
    _swap(arr, pos, curr_pos);
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
