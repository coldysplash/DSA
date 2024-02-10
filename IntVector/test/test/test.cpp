#include "../../src/libvector/IntVector.hpp"

#include <gtest/gtest.h>

#include <iostream>

using namespace intvector;

TEST(IntVector, comparison_operators) {
  {
    IntVector vec1{1, 2, 3};
    IntVector vec2{1, 2, 3};
    bool equal = vec1 == vec2;
    ASSERT_EQ(equal, 1);
  }
  {
    IntVector vec1{1, 0, 3};
    IntVector vec2{1, 2, 3};
    bool equal = vec1 != vec2;
    ASSERT_EQ(equal, 1);
  }
  {
    IntVector vec1{-2, 0, 3};
    IntVector vec2{1, 2, 3};
    bool equal = vec1 < vec2;
    ASSERT_EQ(equal, 1);
  }
  {
    IntVector vec1{-2, 0, 3};
    IntVector vec2{1, 2, 3};
    bool equal = vec1 > vec2;
    ASSERT_EQ(equal, 0);
  }
  {
    IntVector vec1{-2, 0, 3};
    IntVector vec2{1, 2, 3};
    bool equal = vec1 <= vec2;
    ASSERT_EQ(equal, 1);
  }
  {
    IntVector vec1{0, 1, 3};
    IntVector vec2{0, 1, 3};
    bool equal = vec1 >= vec2;
    ASSERT_EQ(equal, 1);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}