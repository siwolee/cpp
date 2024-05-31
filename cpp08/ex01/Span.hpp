#ifndef SPAN_HPP
#define SPAN_HPP
#include <algorithm>
#include <deque>
#include <stdexcept>
#include <vector>

class Span {
 public:
  Span(unsigned int const N);  // throw exception
  ~Span();
  Span(const Span &copy);
  int shortestSpan() const;
  int longestSpan() const;     // throw exception if length == 0 or 1
  void addNumber(int newNum);  // throw exception
  void addMultipleNumber(size_t size, int start);
  void addMultipleNumber(std::vector<int> &container);

 private:
  size_t _length;  // min 10,000
  size_t _size;    // min 10,000
  std::deque<int> _data;
  Span();
  Span &operator=(const Span &copy);
};

#endif