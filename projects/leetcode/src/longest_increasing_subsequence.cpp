#include "leetcode/longest_increasing_subsequence.hpp"

#include <algorithm>
#include <set>
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

int LongestIncreasingSubsequence::lengthOfLIS_v2(std::vector<int> &nums) {
  std::vector<int> optimal_subsequence;
  optimal_subsequence.reserve(nums.size());

  for (std::size_t i = 0; i < nums.size(); ++i) {
    int value = nums[i];

    if (optimal_subsequence.empty() || value > optimal_subsequence.back()) {
      optimal_subsequence.emplace_back(value);
      continue;
    }

    for (std::size_t j = 0; j < optimal_subsequence.size(); ++j) {
      if (optimal_subsequence[j] >= value) {
        optimal_subsequence[j] = value;
        break;
      }
    }
  }

  return optimal_subsequence.size();
}

int LongestIncreasingSubsequence::lengthOfLIS_optimal(std::vector<int> &nums) {
  std::set<int> optimal_subsequence;

  for (std::size_t i = 0; i < nums.size(); ++i) {
    int value = nums[i];

    auto equel = optimal_subsequence.find(value);
    if (equel != optimal_subsequence.end()) {
      continue;
    }

    auto bigger = optimal_subsequence.upper_bound(value);
    if (bigger == optimal_subsequence.end()) {
      optimal_subsequence.insert(value);
      continue;
    }

    optimal_subsequence.erase(bigger);
    optimal_subsequence.insert(value);
  }

  return optimal_subsequence.size();
}

}  // namespace LeetCode
}  // namespace CPPSoup
