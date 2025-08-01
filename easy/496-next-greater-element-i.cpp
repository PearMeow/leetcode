/**
 * @file 496-next-greater-element-i.cpp
 * @author Perry Huang
 * @date 2025-06-26
 * The next greater element of some element x in an array is the first greater element that is to the right of x in
 * the same array. You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of
 * nums2. For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next
 * greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
 * Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
 */

#include <stack>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> next_greater;
        std::stack<int> monDec;
        std::vector<int> res;
        for (int i : nums2) {
            while (!monDec.empty() && monDec.top() < i) {
                next_greater[monDec.top()] = i;
                monDec.pop();
            }
            monDec.push(i);
        }
        for (int i : nums1) {
            if (next_greater.find(i) == next_greater.end()) {
                res.push_back(-1);
            } else {
                res.push_back(next_greater[i]);
            }
        }
        return res;
    }
};
