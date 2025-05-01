#include "leetcode/longest_increasing_subsequence.hpp"

#include <algorithm>
#include <vector>

namespace CPPSoup {
namespace LeetCode {

int LongestIncreasingSubsequence::lengthOfLIS(std::vector<int> &nums) {
  std::vector<int> results;

  for (std::size_t i = 0; i < nums.size(); ++i) {
    int value = nums[i];

    int max = 1;
    for (std::size_t j = 0; j < i; ++j) {
      if (nums[j] < value) {
        max = std::max(max, results[j] + 1);
      }
    }

    results.emplace_back(max);
  }


  return *std::max_element(results.cbegin(), results.cend());
}

}  // namespace LeetCode
}  // namespace CPPSoup
