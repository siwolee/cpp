#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &container, int target) {
  typename T::iterator iter;
  iter = std::find(container.begin(), container.end(), target);
  if (iter == container.end()) throw std::out_of_range("Element not found");
  return (iter);
}

#endif