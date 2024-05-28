#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <stdexcept>

template <typename T>
int easyfind(T &container, int &target) throw(std::out_of_range) {
    std::iterator<T> iter = container.begin();
    try {
        std::cout << iter << std::endl;
        while (iter != container.end()) {
            if (*iter == target)
                return iter;
        }
        iter++;
    }
    throw std::out_of_range("no occurance found");
}

#endif