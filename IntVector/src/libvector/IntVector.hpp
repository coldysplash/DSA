#include <iostream>

namespace intvector {

class IntVector {
private:
  int *arr;

  size_t size_;
  size_t capacity_;

public:
  /* constructors */
  IntVector();

  /* methods */
  size_t size() const;
  size_t capacity() const;
  void reserve(size_t n);
  void resize(size_t n);
  void push_back(int value);

  /* accessors to elements */
  int *begin() const;
  int *end() const;
};

/* comparison operators */

} // namespace intvector