#include <iostream>
// sequence containers : iteratable
#include <array>        //static, contiguous
#include <deque>        // double-ended queue
#include <forward_list> //single ended list (->)
#include <list>         //doubly ended list (<->)
#include <vector>       //dynamic, contiguous
// associative containers: implement sorted data structures
// set, map, multiset, multimap.

#include "easyfind.hpp"

template <typename T> void init_container(T &container, size_t size) {
    typename T::iterator iter = container.begin();
    try {
        for (unsigned int i = 0; i < size; i++) {
            if (iter == container.end()) {
                throw std::out_of_range("Iterator out of range");
            }
            *iter = i;
            iter++;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    // empty test
    {
        std::cout << "*------------empty container test------------*"
                  << std::endl;
        std::array<int, 0> empty_array;
        std::deque<int> empty_deque;
        std::forward_list<int> empty_forward_list;
        std::list<int> empty_list;
        std::vector<int> empty_vector;
        int target = 1;

        try {
            std::cout.width(20);
            std::cout.width(20);
            std::cout << "empty_array: " << easyfind(empty_array, target)
                      << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout.width(20);
            std::cout << "empty_deque: " << easyfind(empty_deque, target)
                      << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout << "emtpy_forward_list: "
                      << easyfind(empty_forward_list, target) << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout.width(20);
            std::cout << "empty_list: " << easyfind(empty_list, target)
                      << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout.width(20);
            std::cout << "empty_vector: " << easyfind(empty_vector, target)
                      << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        std::cout << "*-------------end of empty test-------------*"
                  << std::endl;
    }

    // 100 test
    {
        std::cout << "\n\n*------------100 container test------------*"
                  << std::endl;
        std::array<int, 100> array;
        std::deque<int> deque(100);
        std::forward_list<int> forward_list(100);
        std::list<int> list(100);
        std::vector<int> vector(100);
        int target = 1;

        init_container(array, 100);
        init_container(deque, 100);
        init_container(forward_list, 100);
        init_container(list, 100);
        init_container(vector, 100);

        std::cout << "  * containers are intiallized to 0 - 99" << std::endl;
        std::cout << "  * target: 1" << std::endl;

        try {
            std::cout.width(20);
            std::cout.width(20);
            std::cout << "array: " << easyfind(array, target) << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout.width(20);
            std::cout << "deque: " << easyfind(deque, target) << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout << "emtpy_forward_list: "
                      << easyfind(forward_list, target) << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout.width(20);
            std::cout << "list: " << easyfind(list, target) << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout.width(20);
            std::cout << "vector: " << easyfind(vector, target) << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }

        std::cout << "  * target: 100" << std::endl;

        target = 100;
        try {
            std::cout.width(20);
            std::cout.width(20);
            std::cout << "array: " << easyfind(array, target) << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout.width(20);
            std::cout << "deque: " << easyfind(deque, target) << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout << "emtpy_forward_list: "
                      << easyfind(forward_list, target) << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout.width(20);
            std::cout << "list: " << easyfind(list, target) << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout.width(20);
            std::cout << "vector: " << easyfind(vector, target) << std::endl;
        } catch (std::exception &e) {
            std::cerr.width(20);
            std::cerr << e.what() << std::endl;
        }
        std::cout << "*-------------end of empty test-------------*"
                  << std::endl;
    }
}