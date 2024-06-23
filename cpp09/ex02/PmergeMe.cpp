#include "PmergeMe.hpp"

template <typename T, typename Container>
void _print_all_list(Container <T> arr) {
  for (Container<T>::iterator it = arr.begin() ;
    it != arr.end() ; it++){
      std::cout << " " << *it;
    }
    std::cout << std::endl;
}



void  merge_insert_sort(std::vector<T>& arr){
  std::cout << "Before:";
  _print_all_list(arr);
  std::cout << "After";
  _print_all_list(arr);
}
