#include <gtest/gtest.h>

#include "leetcode/fibonacci_numbers.hpp"

using namespace CPPSoup::LeetCode;

TEST(FibonacciNumbersTestBottomUp, HandlesBaseCases) {
  FibonacciNumbers fib;

  EXPECT_EQ(fib.get_number_by_bottom_up(0), 0);
  EXPECT_EQ(fib.get_number_by_bottom_up(1), 1);
  EXPECT_EQ(fib.get_number_by_bottom_up(2), 1);
}

TEST(FibonacciNumbersTestBottomUp, HandlesGeneralCases) {
  FibonacciNumbers fib;

  EXPECT_EQ(fib.get_number_by_bottom_up(3), 2);
  EXPECT_EQ(fib.get_number_by_bottom_up(4), 3);
  EXPECT_EQ(fib.get_number_by_bottom_up(5), 5);
  EXPECT_EQ(fib.get_number_by_bottom_up(10), 55);
}

TEST(FibonacciNumbersTestTopDown, HandlesBaseCases) {
  FibonacciNumbers fib;

  EXPECT_EQ(fib.get_number_by_top_down(0), 0);
  EXPECT_EQ(fib.get_number_by_top_down(1), 1);
  EXPECT_EQ(fib.get_number_by_top_down(2), 1);
}

TEST(FibonacciNumbersTestTopDown, HandlesGeneralCases) {
  FibonacciNumbers fib;

  EXPECT_EQ(fib.get_number_by_top_down(3), 2);
  EXPECT_EQ(fib.get_number_by_top_down(4), 3);
  EXPECT_EQ(fib.get_number_by_top_down(5), 5);
  EXPECT_EQ(fib.get_number_by_top_down(10), 55);
}
