#include "RPN.hpp"

int main(int ac, char* av[]) {
  if (ac < 2) {
    std::cout << "Error" << std::endl;
    return 1;
  }
  try {
    RPN rpn;
    rpn.calculate(ac, av);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}