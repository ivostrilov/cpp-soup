#include "leetcode/house_robber.hpp"

#include <algorithm>
#include <vector>

namespace CPPSoup {
namespace LeetCode {

static void put_to_cache(int key, int value, std::vector<int> &cache) {
  cache.at(key) = value;
}

static int rob_optimized(std::vector<int>::const_iterator first,
                         std::vector<int>::const_iterator last,
                         std::vector<int> &cache, int n = 0) {
  int cached_value = cache[n];
  if (cached_value != -1) {
    return cached_value;
  }

  auto size = last - first;

  if (size == 1) {
    put_to_cache(n, *first, cache);
    return *first;
  }

  if (size == 2) {
    int max = std::max(*first, *(first + 1));
    put_to_cache(n, max, cache);
    return max;
  }

  if (size == 3) {
    int max = std::max(*first + *(first + 2), *(first + 1));
    put_to_cache(n, max, cache);
    return max;
  }

  int result1 = *first + rob_optimized(first + 2, last, cache, n + 2);
  int result2 = *(first + 1) + rob_optimized(first + 3, last, cache, n + 3);

  int max = std::max(result1, result2);
  put_to_cache(n, max, cache);

  return max;
}

int HouseRobber::rob(std::vector<int> &nums) {
  static std::vector<int> cache;

  cache.resize(100, -1);
  std::ranges::fill(cache, -1);

  return rob_optimized(nums.cbegin(), nums.cend(), cache);
}

}  // namespace LeetCode
}  // namespace CPPSoup
