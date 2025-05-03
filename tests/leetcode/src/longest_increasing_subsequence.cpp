#include "leetcode/longest_increasing_subsequence.hpp"

#include <gtest/gtest.h>

using namespace CPPSoup::LeetCode;

TEST(LongestIncreasingSubsequence, lengthOfLISHandlesBaseCases) {
  LongestIncreasingSubsequence lis;

  std::vector<int> input = {10, 9, 2, 5, 3, 7, 101, 18};
  EXPECT_EQ(lis.lengthOfLIS(input), 4);

  input = {0, 1, 0, 3, 2, 3};
  EXPECT_EQ(lis.lengthOfLIS(input), 4);

  input = {7, 7, 7, 7, 7, 7, 7};
  EXPECT_EQ(lis.lengthOfLIS(input), 1);

  input = {1, 3, 6, 7, 9, 4, 10, 5, 6};
  EXPECT_EQ(lis.lengthOfLIS(input), 6);

  input = {4, 10, 4, 3, 8, 9};
  EXPECT_EQ(lis.lengthOfLIS(input), 3);
}

TEST(LongestIncreasingSubsequence, lengthOfLIS_v2HandlesBaseCases) {
  LongestIncreasingSubsequence lis;

  std::vector<int> input = {10, 9, 2, 5, 3, 7, 101, 18};
  EXPECT_EQ(lis.lengthOfLIS_v2(input), 4);

  input = {0, 1, 0, 3, 2, 3};
  EXPECT_EQ(lis.lengthOfLIS_v2(input), 4);

  input = {7, 7, 7, 7, 7, 7, 7};
  EXPECT_EQ(lis.lengthOfLIS_v2(input), 1);

  input = {1, 3, 6, 7, 9, 4, 10, 5, 6};
  EXPECT_EQ(lis.lengthOfLIS_v2(input), 6);

  input = {4, 10, 4, 3, 8, 9};
  EXPECT_EQ(lis.lengthOfLIS_v2(input), 3);
}
