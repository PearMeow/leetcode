/**
 * @file 1-twosum.cpp
 * @author Perry Huang
 * @date 2024-10-12
 * 1. Two Sum
 * Given an array of integers nums and an integer target, return indices of the two
 * numbers such that they add up to target. You may assume that each input would
 * have exactly one solution, and you may not use the same element twice. You can
 * return the answer in any order.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
  std::unordered_map<int, int> numsMap;
  for (size_t ind = 0; ind < nums.size(); ++ind) {  // iterate through nums
    int other = target - nums[ind];      // other number that adds up to target
    if (numsMap[other] != 0) {           // if that other number exists
      return {(int)ind, numsMap[other] - 1};  // return the vector with the indicies
    }
    numsMap[nums[ind]] = ind + 1;  // index + 1 to avoid 0
  }
  return {};
}

int main() {
  std::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> res = twoSum(test, 3);
  std::cout << res[0] << " " << res[1] << std::endl;
}
