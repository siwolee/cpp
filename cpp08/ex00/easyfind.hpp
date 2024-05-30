#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <exception>

template <typename T> int easyfind(T &container, int target) {
    typename T::iterator iter = container.begin();
    while (iter != container.end()) {
        if (*iter == target)
            return *iter;
        iter++;
    }
    throw std::out_of_range("Element not found");
}

#endif