#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <exception>
#include <iostream>
#include <stack>

class RPN {
 public:
  RPN();
  ~RPN();
  void calculate(int ac, char* av[]);

 private:
  std::stack<int> _data;

  RPN(const RPN& copy);
  RPN& operator=(const RPN& copy);
};

#endif