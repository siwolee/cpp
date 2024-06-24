#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <typename Container>
void print_all_list(Container arr);

// template <typename T, typename Container = std::deque<T> >
template <typename T>
void merge_insert_sort(std::vector<T>& arr, size_t rank);

#endif