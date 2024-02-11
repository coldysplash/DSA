#include "../../src/libvector/IntVector.hpp"

#include <gtest/gtest.h>

#include <iostream>

using namespace intvector;

TEST(IntVector, rule_of_5) {
  // Copy constructor
  {
    IntVector vec{1, 2, 3, 4, 5};
    IntVector cpy_vec(vec);
    ASSERT_EQ(vec, cpy_vec);
  }
  // Move constructor
  {
    IntVector vec{1, 2, 3, 4, 5};
    IntVector cpy_vec(std::move(vec));
    ASSERT_EQ(cpy_vec, IntVector({1, 2, 3, 4, 5}));
  }
  // Operator =
  {
    IntVector vec{1, 2, 3, 4, 5};
    IntVector cpy_vec;
    cpy_vec = vec;
    ASSERT_EQ(vec, cpy_vec);
  }
  // Move operator =
  {
    IntVector vec{1, 2, 3, 4, 5};
    IntVector cpy_vec;
    cpy_vec = std::move(vec);
    ASSERT_EQ(cpy_vec, IntVector({1, 2, 3, 4, 5}));
  }
}

// operator ==
TEST(IntVector, equality) {
  IntVector vec1{1, 2, 3};
  IntVector vec2{1, 2, 3};
  bool equal = vec1 == vec2;
  ASSERT_EQ(equal, 1);
}

// operator !=
TEST(IntVector, not_equality) {
  IntVector vec1{1, 0, 3};
  IntVector vec2{1, 2, 3};
  bool equal = vec1 != vec2;
  ASSERT_EQ(equal, 1);
}

// operator <
TEST(IntVector, less) {
  IntVector vec1{-2, 0, 3};
  IntVector vec2{1, 2, 3};
  bool equal = vec1 < vec2;
  ASSERT_EQ(equal, 1);
  IntVector vec1_e;
  IntVector vec2_e{1};
  bool eq = vec1_e < vec2_e;
  ASSERT_EQ(eq, 1);
}

// operator >
TEST(IntVector, greater) {
  IntVector vec1{-2, 0, 3};
  IntVector vec2{1, 2, 3};
  bool equal = vec1 > vec2;
  ASSERT_EQ(equal, 0);
}

// operator <=
TEST(IntVector, less_eq) {
  IntVector vec1{-2, 0, 3};
  IntVector vec2{1, 2, 3};
  bool equal = vec1 <= vec2;
  ASSERT_EQ(equal, 1);
}

// operator >=
TEST(IntVector, greater_eq) {
  {
    IntVector vec1{0, 1, 3};
    IntVector vec2{0, 1, 3};
    bool equal = vec1 >= vec2;
    ASSERT_EQ(equal, 1);
  }
  {
    IntVector vec1{0, 1, 3, 5, 6};
    IntVector vec2{0, 1, 3};
    bool equal = vec1 >= vec2;
    ASSERT_EQ(equal, 1);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}