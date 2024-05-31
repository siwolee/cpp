#include "Span.hpp"

Span::Span(unsigned int const N) : _length(0), _size(N) {
  if (_size == 0) _size = 1;
  _data = std::deque<int>();
}

Span::~Span() {}

Span::Span(const Span &copy)
    : _length(copy._length), _size(copy._size), _data(copy._data) {}

void Span::addNumber(int newNum) {
  if (_length >= _size)
    throw std::out_of_range("SPAN: No available space left on this span");
  _data.push_back(newNum);
  _length++;
  std::sort(_data.begin(), _data.end());
}

void Span::addMultipleNumber(size_t size, int start) {
  if (_size < _length + size)
    throw std::out_of_range("SPAN: left space is smaller then adding size");
  for (size_t i = 0; i < size; i++) {
    _data.push_back(start);
    _length++;
    start++;
  }
  std::sort(_data.begin(), _data.end());
}

void Span::addMultipleNumber(std::vector<int> &container) {
  if (_size < _length + container.size())
    throw std::out_of_range("SPAN: left space is smaller than container size");
  for (std::vector<int>::iterator iter = container.begin();
       iter != container.end(); iter++) {
    _data.push_back(*iter);
    _length++;
  }
  std::sort(_data.begin(), _data.end());
  for (std::vector<int>::iterator iter = container.begin();
       iter != container.end(); iter++) {
  }
}

int Span::shortestSpan() const {
  if (_size <= 1) throw std::out_of_range("SPAN: No shortest span");
  return _data.front();
}

int Span::longestSpan() const {
  if (_size <= 1) throw std::out_of_range("SPAN: No longest span");
  return _data.back();
}
// member function to add at least 1000 numbers

Span::Span() : _length(0), _size(1), _data(std::deque<int>()) {}

Span &Span::operator=(const Span &copy) {
  if (this != &copy) {
    _length = copy._length;
    _size = copy._size;
    _data = std::deque<int>(copy._data);
  }
  return *this;
};