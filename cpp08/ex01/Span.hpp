#ifndef SPAN_HPP
#define SPAN_HPP
#include <stdexcept>
#include <vector>

class Span {
  public:
    Span(int N); // throw exception
    ~Span();
    Span(const Span &copy);
    int shortestSpan() const;
    int longestSpan() const;    // throw exception if length == 0 or 1
    void addNumber(int newNum); // throw exception
    void addMultipleNumber(size_t size, int start);
    void addMultipleNumber(std::vector<int> &container);

  private:
    size_t _length; // min 10,000
    size_t _size;   // min 10,000
    int *_data;
    Span();
    Span &operator=(const Span &assign);
};

#endif