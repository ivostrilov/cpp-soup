#pragma once

// https://leetcode.com/problems/longest-increasing-subsequence/description/
//
// Given an integer array nums, return the length of the longest strictly
// increasing subsequence.
//
// Example 1:
// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
// length is 4.
//
// Example 2:
// Input: nums = [0,1,0,3,2,3]
// Output: 4
//
// Example 3:
// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
//
// Constraints:
// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104

#include <vector>

namespace CPPSoup {
namespace LeetCode {

class LongestIncreasingSubsequence {
 public:
  // O(n^2)
  int lengthOfLIS(std::vector<int>& nums);

  // O(n^2)
  int lengthOfLIS_v2(std::vector<int>& nums);

  // O(n*log(n))
  int lengthOfLIS_optimal(std::vector<int>& nums);
};

}  // namespace LeetCode
}  // namespace CPPSoup
