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

  /* Rule of 5 */
  IntVector(const IntVector &v_copy);
  IntVector(IntVector &&v_copy);
  IntVector &operator=(const IntVector &vec);
  IntVector &operator=(IntVector &&vec);
  ~IntVector();

  size_t size() const;
  size_t capacity() const;

  /* accessors to elements */
  int *begin() const;
  int *end() const;
  int &operator[](const size_t index) noexcept;
};

/* Standard constructor */
IntVector::IntVector() : arr(nullptr), size_(0), capacity_(0) {}

/* std::initializer_list constructor */
IntVector::IntVector(const std::initializer_list<int> &init_list)
    : arr(new int[init_list.size()]), size_(init_list.size()),
      capacity_(init_list.size()) {

  size_t i = 0;
  for (const auto &val : init_list) {
    arr[i] = val;
    ++i;
  }
}

/* Copy constructor */
IntVector::IntVector(const IntVector &v_copy) {
  arr = new int[v_copy.capacity_];
  size_ = v_copy.size_;
  capacity_ = v_copy.capacity_;
  for (size_t i = 0; i != size_; ++i) {
    arr[i] = v_copy.arr[i];
  }
}

/* Move constructor */
IntVector::IntVector(IntVector &&v_copy)
    : size_(std::move(v_copy.size_)), capacity_(std::move(v_copy.capacity_)) {

  arr = std::move(v_copy.arr);

  v_copy.arr = nullptr;
  v_copy.size_ = 0;
  v_copy.capacity_ = 0;
}

/* Copy assignment operator */
IntVector &IntVector::operator=(const IntVector &vec) {
  if (vec.arr == arr) {
    return *this;
  }

  delete[] arr;
  arr = new int[vec.capacity_];

  size_ = vec.size_;
  capacity_ = vec.capacity_;

  for (size_t i = 0; i < size_; ++i) {
    arr[i] = vec.arr[i];
  }

  return *this;
}

/* Move assignment operator */
IntVector &IntVector::operator=(IntVector &&vec) {
  if (vec.arr == arr) {
    return *this;
  }

  std::swap(arr, vec.arr);
  std::swap(size_, vec.size_);
  std::swap(capacity_, vec.capacity_);

  vec.arr = nullptr;
  vec.size_ = 0;
  vec.capacity_ = 0;

  return *this;
}

/* Destructor */
IntVector::~IntVector() { delete[] arr; }

size_t IntVector::size() const { return size_; }
size_t IntVector::capacity() const { return capacity_; }

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