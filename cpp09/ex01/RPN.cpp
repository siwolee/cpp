#include "RPN.hpp"

RPN::RPN() : _data(std::stack<int>()){};
RPN::RPN(const RPN& copy) : _data(copy._data){};
RPN& RPN::operator=(const RPN& copy) {
  if (this != &copy) {
    _data = copy._data;
  }
  return *this;
}
RPN::~RPN() {
  while (!_data.empty()) {
    _data.pop();
  }
}

void RPN::calculate(int ac, char* av[]) {
  int i = 1;
  int j = 0;
  while (i < ac) {
    j = 0;
    while (av[i][j]) {
      if (av[i][j] == ' ') {
        j++;
        continue;
      }
      if (std::isdigit(av[i][j])) {
        if (av[i][j + 1] != ' ') {
          while (av[i][j] != ' ') j++;
          continue;
        }
        _data.push(atoi(&av[i][j]));
      } else {
        if (_data.size() < 2) {
          throw std::invalid_argument("Error");
        }
        int a = _data.top();
        _data.pop();
        int b = _data.top();
        _data.pop();
        switch (av[i][j]) {
          case '+':
            _data.push(b + a);
            break;
          case '-':
            _data.push(b - a);
            break;
          case '/':
            _data.push(b / a);
            break;
          case '*':
            _data.push(b * a);
            break;
          default:
            throw std::invalid_argument("Error");
        }
      }
      j++;
    }
    i++;
  }
  std::cout << _data.top() << std::endl;
}