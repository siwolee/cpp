#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <class T> class Array {
  public:
    Array() : data(new T[0]()), data_count(1) {}
    Array(unsigned int n) : data(new T[n]()), data_count(n) {
        if (n == 0)
            data_count = 1;
    }

    Array(const Array &ref) : data(NULL), data_count(0) { *this = ref; }

    Array &operator=(const Array &ref) {
        if (this != &ref) {
            delete[] data;
            data_count = ref.data_count;
            data = new T[data_count];
            for (unsigned int i = 0; i < data_count; i++) {
                data[i] = ref.data[i];
            }
        }
        return *this;
    }

    ~Array() { delete[] data; }

    T &operator[](int index) const {
        if (index < 0 || static_cast<unsigned int>(index) >= data_count) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    unsigned int size() const { return data_count; }

  private:
    T *data;
    unsigned int data_count;
};

#endif // ARRAY_HPP
