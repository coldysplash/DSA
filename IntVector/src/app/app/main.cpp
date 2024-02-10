#include "../../libvector/IntVector.hpp"

#include <iostream>
#include <vector>

int main() {

  using namespace intvector;

  IntVector vec{2, 0, 0, 0};
  IntVector vec2{0, 1, 2, 3};

  std::vector<int> vec1;

  bool equal = vec == vec2;
  bool equal2 = vec < vec2;

  std::cout << equal << '\n';
  std::cout << equal2 << '\n';

  return 0;
}
