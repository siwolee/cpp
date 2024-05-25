#ifndef SPAN_HPP
#define SPAN_HPP
#include <stdexcept>

class Span {
 public:
  Span(unsigned int& N);
  ~Span();
  Span(const Span& copy);
  void addNumber(int& newNum);  // throw OutOfBound exception
  int shortestSpan() const;
  int longestSpan() const;  // throw exception if length == 0 or 1
                            // range of iterators;
                            // member function to add at least 1000 numbers

 private:
  unsigned int length;  // min 10,000
  int* data;
  Span();
  Span& operator=(const Span& assign);
};

#endif