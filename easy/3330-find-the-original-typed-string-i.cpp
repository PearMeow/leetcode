/**
 * @file 3330-find-the-original-typed-string-i.cpp
 * @author Perry Huang
 * @date 2025-06-30
 * 3330. Find the Original Typed String I
 * Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a
 * key for too long, resulting in a character being typed multiple times. Although Alice tried to focus on her
 * typing, she is aware that she may still have done this at most once. You are given a string word, which
 * represents the final output displayed on Alice's screen. Return the total number of possible original strings
 * that Alice might have intended to type.
 */

#include <string>

class Solution {
public:
    int possibleStringCount(const std::string& word) {
        int res = 0;
        char prev = ' ';
        for (char c : word) {
            if (prev == ' ') {
                ++res;
                prev = c;
            } else if (c == prev) {
                ++res;
            } else {
                prev = c;
            }
        }
        return res;
    }
};
