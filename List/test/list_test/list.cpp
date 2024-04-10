#include <list/list.hpp>

#include <gtest/gtest.h>

#include <algorithm>
#include <list>

/* test iterator and constructor begin end */
TEST(list_test, iterator_test) {

  list::List<int> eq_list{1, 2, 3, 4};
  list::List<int>::iterator beg = eq_list.begin();
  list::List<int>::iterator end = eq_list.end();

  list::List<int> expected(beg, end);

  ASSERT_EQ(eq_list, expected);
}

TEST(list_test, front_back_test) {

  list::List<int> eq_list{1, 2, 3, 4};

  ASSERT_EQ(eq_list.front(), 1);
  ASSERT_EQ(eq_list.back(), 4);
}

/* test push_back and push_front */
TEST(list_test, push_test) {
  {
    list::List<int> eq_list{1, 2, 3};
    eq_list.push_back(5);
    list::List<int> expected{1, 2, 3, 5};
    ASSERT_EQ(eq_list, expected);
  }
  {
    list::List<int> eq_list{1, 2, 3};
    eq_list.push_front(5);
    list::List<int> expected{5, 1, 2, 3};
    ASSERT_EQ(eq_list, expected);
  }
}

/* test empty and size */
TEST(list_test, empty_size_test) {
  list::List<int> eq_list{1, 2, 3};
  ASSERT_EQ(eq_list.empty(), false);
  list::List<int> eq_list_1{};
  ASSERT_EQ(eq_list_1.empty(), true);
  ASSERT_EQ(eq_list.size(), 3);
  ASSERT_EQ(eq_list_1.size(), 0);
}

/* test Copy constructor */
TEST(list_test, copy_constructor_test) {

  list::List<char> eq_list{'a', 'b', 'c', 'd'};
  list::List<char> copy_list(eq_list);

  ASSERT_EQ(eq_list, copy_list);
}

/* test Move constructor */
TEST(list_test, move_constructor_test) {

  list::List<int> eq_list{1, 2, 3};
  list::List<int> move_list(std::move(eq_list));

  ASSERT_EQ((list::List<int>{1, 2, 3}), move_list);
}

/* test Copy assignment operator */
TEST(list_test, copy_assignment_test) {
  {
    list::List<char> eq_list{'a', 'b', 'c', 'd'};
    list::List<char> copy_list{'a', 'b', 'c'};
    copy_list = eq_list;

    ASSERT_EQ(eq_list, copy_list);
  }
  {
    list::List<char> eq_list{'a', 'b', 'c'};
    list::List<char> copy_list{'a', 'b', 'c'};
    copy_list = eq_list;

    ASSERT_EQ(eq_list, copy_list);
  }
}

/* test Move assignment operator */
TEST(list_test, move_assignment_test) {

  list::List<int> eq_list{1, 2, 3};
  list::List<int> move_list = std::move(eq_list);

  ASSERT_EQ((list::List<int>{1, 2, 3}), move_list);
}

/* test my list with stl methods */
TEST(list_test, list_stl_test) {
  /* std::find */
  {
    list::List<int> eq_list{1, 2, 3};
    list::List<int>::iterator it = std::find(eq_list.begin(), eq_list.end(), 2);

    ASSERT_EQ(*it, 2);
  }
  /* std::reverse */
  {
    list::List<int> eq_list{1, 2, 3};
    std::reverse(eq_list.begin(), eq_list.end());

    ASSERT_EQ(eq_list, (list::List<int>{3, 2, 1}));
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}