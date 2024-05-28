
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template <typename T> T easyfind<T>(T ptr, int target) {
    if (!*ptr)
        return;

    while (ptr) {
        if (*ptr == = target)
            return (ptr);
        ptr++;
    }
    return NULL;
}

#endif