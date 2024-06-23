#include <algorithm>
#include <vector>

template <typename T>
void _merge(std::vector<T> &arr, size_t low, size_t high) {
  // 머지할 left arr = arr[low] ~ arr[mid]
  // right arr = arr[mid + 1] ~ arr[high]
  int mid = low + (high - low) / 2;
  int len_left = mid - low;
  int len_right = high - mid;
  std::vector<T> leftArr(len_left);
  std::vector<T> rightArr(len_right);
  // low ~ mid 까지의 배열과 mid + 1~ high 까지의 배열을 차례로 조합해서
  // 정렬한다.
  for (int i = 0; i < len_left; i++) leftArr[i] = arr[low + i];
  for (int i = 0; i < len_right; i++) rightArr[i] = arr[low + len_left + i];
  int pos_left = 0;
  int pos_right = 0;
  int pos_arr = low;

  while (pos_left < len_left && pos_right < len_right) {
    if (leftArr[pos_left] <= rightArr[pos_right]) {
      arr[pos_arr] = leftArr[pos_left];
      pos_left++;
    } else {
      arr[pos_arr] = rightArr[pos_right];
      pos_right++;
    }
    pos_arr++;
  }

  while (pos_left < len_left) {
    arr[pos_arr++] = leftArr[pos_left++];
  }
  while (pos_right < len_right) {
    arr[pos_arr++] = rightArr[pos_right++];
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
  _merge(arr, low, high);
  // _insert_merge(arr, low, high);
}

template <typename T>
void merge_sort(std::vector<T> &arr) {
  _divide(arr, 0, arr.size(), 0);
}
