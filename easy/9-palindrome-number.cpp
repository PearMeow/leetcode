/**
 * @file 9-palindrome-number.cpp
 * @author Perry Huang
 * @date 2024-10-12
 * 9. Palindrome Number
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 */

#include <cstdio>  // for size_t definition

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        std::size_t rvrs = 0, count = 0, orig = x;
        while (orig) {
            rvrs *= 10;
            rvrs += orig % 10;
            orig /= 10;
        }
        while (x) {
            if (!(rvrs % 10 == x % 10)) return false;
            rvrs /= 10;
            x /= 10;
        }
        return true;
    }
};
