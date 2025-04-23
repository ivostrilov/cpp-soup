#include "leetcode/fibonacci_numbers.hpp"

namespace CPPSoup {
namespace LeetCode {

std::size_t FibonacciNumbers::get_number_by_bottom_up(std::size_t n) {
  if (n == 0) {
    return 0;
  }

  if (n == 1 || n == 2) {
    return 1;
  }

  std::size_t prev = 1;
  std::size_t result = 2;

  for (std::size_t i = 3; i < n; ++i) {
    std::size_t remainder = result;
    result += prev;
    prev = remainder;
  }

  return result;
}

std::size_t FibonacciNumbers::get_number_by_top_down(std::size_t n) {
  if (n == 0) {
    return 0;
  }

  if (n == 1 || n == 2) {
    return 1;
  }

  return get_number_by_top_down(n - 1) + get_number_by_top_down(n - 2);
}

}  // namespace LeetCode
}  // namespace CPPSoup
