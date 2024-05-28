#include "easyfind.hpp"
#include <iostream>

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << ::easyfind(arr, 2) << std::endl;
}