/**
 * @file 2900-longest-unequal-adjacent-groups-subsequence-i.cpp
 * @author Perry Huang
 * @date 2025-05-15
 * 2900. Longest Unequal Adjacent Groups Subsequence I
 * You are given a string array words and a binary array groups both of length n, where words[i] is associated with
 * group s[i]. Your task is to select the longest alternating subsequence from words. A subsequence of words is
 * alternating if for any two consecutive strings in the sequence, their corresponding elements in the binary array
 * groups differ. Essentially you are to choose strings such that adjacent elements have non-matching corresponding
 * bits in the groups array. Formally, you need to find the longest subsequence of an array of indices [0, 1, ...,
 * n - 1] denoted as [i0, i1, ..., ik-1], such that groups[ij] != groups[ij+1] for each 0 <= j < k - 1 and then
 * find the words corresponding to these indices. Return the selected subsequence. If there are multiple answers,
 * return any of them. Note: The elements in words are distinct.
 */

#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> getLongestSubsequence(std::vector<std::string>& words, std::vector<int>& groups) {
        bool bit = groups[0];
        std::vector<std::string> sub;
        for (size_t i = 0; i < std::min(words.size(), groups.size()); ++i) {
            if (groups[i] == bit) {
                sub.push_back(words[i]);
                bit = !bit;
            }
        }
        return sub;
    }
};
