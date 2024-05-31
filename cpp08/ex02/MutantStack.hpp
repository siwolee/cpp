#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
 public:
  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;
  typedef typename Container::reverse_iterator reverse_iterator;
  typedef typename Container::const_reverse_iterator const_reverse_iterator;

  MutantStack() {}
  ~MutantStack() {}
  MutantStack(MutantStack const& copy) : Container(copy->c) {}
  MutantStack& operator=(MutantStack const& copy) {
    if (this != &copy) {
      std::stack<T, Container>::operator=(*this, copy);
    }
    return *this;
  }

  iterator begin() { return this->c.begin(); }
  iterator rbegin() { return this->c.begin(); }
  const_iterator begin() const { return this->c.begin(); }
  const_iterator rbegin() const { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  iterator rend() { return this->c.end(); }
  const_iterator end() const { return this->c.end(); }
  const_iterator rend() const { return this->c.end(); }

  void push(T elem) { this->c.push_back(elem); }
  T& top() { return this->c.back(); }
  void pop() { this->c.pop_back(); }
  size_t size() { return this->c.size(); }
  bool empty() const { return this->c.empty(); }
};

#endif