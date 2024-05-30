#include "Span.hpp"

Span::Span(int N) : _length(0), _size(N), _data(NULL) {
    if (N <= 0) {
        throw std::out_of_range("Span size must be positive");
    }
    _data = new int[N];
}

Span::~Span() { delete[] _data; }
Span::Span(const Span &copy) : _length(copy._length), _size(copy._size) {
    if (copy._data != _data)
        delete _data;
    _data = new int[_size];
    for (size_t idx = 0; idx < _length; idx++) {
        _data[idx] = copy._data[idx];
    }
}
void Span::addNumber(int newNum) {
    if (_length >= _size)
        throw std::out_of_range("SPAN: No available space left on this span");
    _data[_length] = newNum;
    _length++;
}

void Span::addMultipleNumber(size_t size, int start) {
    if (_size < _length + size)
        throw std::out_of_range("SPAN: left space is smaller then adding size");
    for (size_t i = 0; i < size; i++) {
        _data[_length] = start;
        _length++;
        start++;
    }
}

void Span::addMultipleNumber(std::vector<int> &container) {
    if (_size < _length + container.size())
        throw std::out_of_range(
            "SPAN: left space is smaller than container size");
    for (std::vector<int>::iterator iter = container.begin();
         iter != container.end(); iter++) {
        _data[_length] = *iter;
        _length++;
    }
}

int Span::shortestSpan() const {
    if (_size <= 1)
        throw std::out_of_range("SPAN: No shortest span");
    int res = _data[0];
    for (size_t i = 1; i < _length; i++) {
        if (_data[i] < res) {
            res = _data[i];
        }
    }
    return res;
}
int Span::longestSpan() const {
    if (_size <= 1)
        throw std::out_of_range("SPAN: No longest span");
    int res = _data[0];
    for (size_t i = 1; i < _length; i++) {
        if (_data[i] > res) {
            res = _data[i];
        }
    }
    return res;
}
// member function to add at least 1000 numbers

Span::Span() : _length(0), _size(0), _data(NULL) {}

Span &Span::operator=(const Span &assign) {
    if (this != &assign) {
        if (assign._data != _data)
            delete _data;
        _data = new int[_size];
        for (size_t idx = 0; idx < _length; idx++) {
            _data[idx] = assign._data[idx];
        }
    }
    return *this;
};