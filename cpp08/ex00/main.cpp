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

int main() {
    // empty test
    {
        std::array<int, 0> empty_array;
        // std::deque<int> empty_deque;
        // std::forward_list<int> empty_forward_list;
        // std::list<int> empty_list;
        // std::vector<int> empty_vector;
        int target = 1;

        try {
            std::cout << "Array empty :" << easyfind(empty_array, target)
                      << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}