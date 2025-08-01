/**
 * @file 15-3sum.cpp
 * @author Perry Huang
 * @date 2024-02-26
 * 15. 3Sum
 * Given an integer array nums, return all the triplets
 * [nums[i], nums[j], nums[k]] such that
 * i != j, i != k, and j != k
 * nums[i] + nums[j] + nums[k] == 0.
 * Notice that the solution set must not contain duplicate triplets.
 */

#include <vector>

class Solution {
public:
    std::vector<int>& mergeSort(std::vector<int>& unsorted) {
        if (unsorted.size() == 1) return unsorted;
        size_t mid = unsorted.size() / 2;
        std::vector<int> left(mid), right(unsorted.size() - mid);
        for (size_t i = 0; i < mid; ++i) {
            left[i] = unsorted[i];
        }
        for (size_t i = mid; i < unsorted.size(); ++i) {
            right[i - mid] = unsorted[i];
        }
        mergeSort(left), mergeSort(right);
        size_t posL = 0, posR = 0, sortPos = 0;
        while (posL < left.size() && posR < right.size()) {
            if (left[posL] <= right[posR]) {
                unsorted[sortPos] = left[posL];
                ++posL;
            } else {
                unsorted[sortPos] = right[posR];
                ++posR;
            }
            ++sortPos;
        }
        if (posL == left.size()) {
            for (size_t i = posR; i < right.size(); ++i) {
                unsorted[sortPos] = right[i];
                ++sortPos;
            }
        } else {
            for (size_t i = posL; i < left.size(); ++i) {
                unsorted[sortPos] = left[i];
                ++sortPos;
            }
        }
        return unsorted;
    }
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        mergeSort(nums);
        std::vector<std::vector<int>> triplets;
        return triplets;
    }
};
