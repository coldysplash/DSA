#pragma once

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <utility>

namespace vector_cow {

template <typename T> class Vector {
public:
  using value_type = T;
  using size_type = size_t;
  using difference_type = std::ptrdiff_t;
  using reference = value_type &;
  using const_reference = const value_type &;
  using pointer = value_type *;
  using const_pointer = const value_type *;

  Vector() = default;
  Vector(const Vector &other)
      : begin_(other.begin_), size_(other.size_), capacity_(other.capacity_) {}

  Vector(Vector &&other)
      : begin_(other.begin_), size_(other.size_), capacity_(other.capacity_) {
    other.begin_ = nullptr;
    other.size_ = other.capacity_ = 0;
  }

  Vector &operator=(const Vector &other) {
    if (this != &other) {
      other.begin_ = this->begin_;
      other.size_ = this->size_;
      other.capacity_ = this->capacity_;
    }
    return *this;
  }

  Vector &operator=(Vector &&other) {
    Vector tmp(std::move(other));
    tmp.swap(*this);
    return *this;
  };

  ~Vector() {
    for (auto current = begin_; current != begin_ + size_; ++current) {
      current->~T();
    }
    operator delete(begin_);
  };

  // explicit Vector(size_type sizes)
  //     : begin_(static_cast<T *>(operator new(sizeof(T) * sizes))),
  //     size_(sizes),
  //       capacity_(sizes) {}

  // Vector(size_type size, const_reference value);

  explicit Vector(std::initializer_list<T> items)
      : begin_(static_cast<T *>(operator new(sizeof(T) * items.size()))),
        size_(items.size()), capacity_(size_) {
    std::uninitialized_move(items.begin(), items.end(), begin_);
  }
  //   Vector(iterator first, iterator end);

  pointer begin() { return begin_; }
  pointer end() { return begin_ + size_; }
  size_type size() const { return size_; }
  size_type capacity() const { return capacity_; }

private:
  void detach();
  void swap(Vector &obj) noexcept {
    obj.begin_ = this->begin_;
    obj.size_ = this->size_;
    obj.capacity_ = this->capacity_;
  }

  pointer begin_ = nullptr;
  size_type size_ = 0;
  size_type capacity_ = 0;
};

} // namespace vector_cow