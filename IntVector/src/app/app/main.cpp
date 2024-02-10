#include "../../libvector/IntVector.hpp"

#include <iostream>
#include <vector>

int main() {

  using namespace intvector;

  IntVector vec1{2, 0, 0, 0};
  IntVector vec2{0, 1, 2, 3};

  bool equal = vec1 == vec2;
  bool equal2 = vec1 < vec2;

  std::cout << equal << '\n';
  std::cout << equal2 << '\n';

  return 0;
}
