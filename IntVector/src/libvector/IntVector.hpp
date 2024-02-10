#include <iostream>

#include <algorithm>

namespace intvector {

class IntVector {
private:
  int *arr;
  size_t size_;
  size_t capacity_;

public:
  /* constructors */
  IntVector();
  IntVector(const std::initializer_list<int> &init_list);

  /* capacity */
  size_t size() const;
  size_t capacity() const;
  void reserve(size_t n_capa);

  void push_back(int value);

  /* accessors to elements */
  int *begin() const;
  int *end() const;
  int &operator[](const size_t index) noexcept;

  ~IntVector() { delete[] arr; }
};

IntVector::IntVector() : arr(nullptr), size_(0), capacity_(0) {}

IntVector::IntVector(const std::initializer_list<int> &init_list)
    : arr(new int[init_list.size()]), size_(init_list.size()),
      capacity_(init_list.size()) {

  size_t i = 0;
  for (const auto &val : init_list) {
    arr[i] = val;
    ++i;
  }
}

size_t IntVector::size() const { return size_; }
size_t IntVector::capacity() const { return capacity_; }

void IntVector::reserve(size_t n_capa) {
  if (n_capa > capacity_) {
    int *newarr = new int[n_capa];
    for (size_t i = 0; i < size_; ++i) {
      newarr[i] = arr[i];
    }
    delete[] arr;

    arr = newarr;
    capacity_ = n_capa;

    delete[] newarr;
  }
}

void IntVector::push_back(int value) {
  if (capacity_ == size_) {
    reserve(2 * size_);
  }
  arr[size_] = value;
  ++size_;
}

int *IntVector::begin() const { return arr; }

int *IntVector::end() const { return (arr + size_); }

int &IntVector::operator[](const size_t index) noexcept { return arr[index]; }

/* comparison operators */

inline bool operator==(const IntVector &lhs, const IntVector &rhs) {
  return (
      lhs.size() == rhs.size() &&
      std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

inline bool operator<(const IntVector &lhs, const IntVector &rhs) {
  return std::lexicographical_compare(
      lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

inline bool operator!=(const IntVector &lhs, const IntVector &rhs) {
  return !(lhs == rhs);
}

inline bool operator>(const IntVector &lhs, const IntVector &rhs) {
  return (rhs < lhs);
}

inline bool operator<=(const IntVector &lhs, const IntVector &rhs) {
  return !(rhs < lhs);
}

inline bool operator>=(const IntVector &lhs, const IntVector &rhs) {
  return !(lhs < rhs);
}

} // namespace intvector