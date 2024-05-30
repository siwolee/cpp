#include "Span.hpp"
#include <iostream>
#include <time.h>
#include <vector>

int main() {
    // document
    {
        std::cout << "*------------docs main test------------*" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout.width(20);
        std::cout << "shortest : " << sp.shortestSpan() << std::endl;
        std::cout.width(20);
        std::cout << "longest : " << sp.longestSpan() << std::endl;
        std::cout << "\n" << std::endl;
    }
    {
        std::cout << "*------------addMultiple: increase------------*"
                  << std::endl;
        Span sp = Span(10000);
        sp.addMultipleNumber(10000, 1);
        std::cout << " - initialized from 1 to 10000" << std::endl;
        std::cout.width(20);
        std::cout << "shortest : " << sp.shortestSpan() << std::endl;
        std::cout.width(20);
        std::cout << "longest : " << sp.longestSpan() << std::endl;
        std::cout << "\n" << std::endl;
    }
    {
        std::cout << "*------------addMultiple: random------------*"
                  << std::endl;
        Span sp = Span(10000);
        std::vector<int> v(10000);

        std::srand(std::time(0));
        for (std::vector<int>::iterator iter = v.begin(); iter != v.end();
             iter++) {
            *iter = std::rand();
        }
        sp.addMultipleNumber(v);
        std::sort(v.begin(), v.end());
        std::cout.width(20);
        std::cout << "shortest : " << sp.shortestSpan() << std::endl;
        std::cout.width(20);
        std::cout << "(sort_vec) : " << *(v.begin()) << std::endl;
        std::cout.width(20);
        std::cout << "longest : " << sp.longestSpan() << std::endl;
        std::cout.width(20);
        std::cout << "(sort_vec) : " << *(v.end() - 1) << std::endl;
        std::cout << "\n" << std::endl;
    }
    {
        std::cout << "*------------addMultiple: exception test------------*"
                  << std::endl;
        Span sp = Span(30000);
        std::vector<int> v(29990);
        std::srand(std::time(0));
        for (std::vector<int>::iterator iter = v.begin(); iter != v.end();
             iter++) {
            *iter = std::rand();
        }
        sp.addMultipleNumber(v);
        try {
            sp.addMultipleNumber(100, 1);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        } // err

        std::sort(v.begin(), v.end());
        std::cout.width(20);
        std::cout << "shortest : " << sp.shortestSpan() << std::endl;
        std::cout.width(20);
        std::cout << "(sort_vec) : " << *(v.begin()) << std::endl;
        std::cout.width(20);
        std::cout << "longest : " << sp.longestSpan() << std::endl;
        std::cout.width(20);
        std::cout << "(sort_vec) : " << *(v.end() - 1) << std::endl;
        std::cout << "\n" << std::endl;
    }
    return 0;
}
