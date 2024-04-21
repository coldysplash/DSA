#include <vector-cow.hpp>

#include <gtest/gtest.h>

#include <iostream>
#include <string>

// TEST(test_vector, initializer_constructor) {
//   vector_cow::Vector<std::string> v(2, "hello");
//   for (auto it = v.begin(); it != v.end(); ++it) {
//     std::cout << *it << ' ';
//   }
//   std::cout << '\n' << v.capacity() << ' ' << v.size() << '\n';
// }

TEST(test_vector, reserve) {
  vector_cow::Vector<std::string> v(2, "hello");
  v.reserve(5);
  v.reserve(2);
  ASSERT_EQ(v.capacity(), 5);
}

TEST(test_vector, push_back) {
  vector_cow::Vector<int> v(2, 5);
  v.push_back(2);
  vector_cow::Vector<int> expect{5, 5, 2};
  // ASSERT_EQ(v, expect);

  for (auto it1 = v.begin(); it1 != v.end(); ++it1) {
    std::cout << *it1 << '\n';
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}