/**
 * @file 12-integer-to-roman.cpp
 * @author Perry Huang
 * @date 2024-02-25
 * 12. Integer to Roman
 * Given an integer, convert it to a roman numeral.
 */

#include <string>
#include <unordered_map>

class Solution {
public:
    std::string intToRoman(int num) {
        std::string romNum;
        std::unordered_map<int, std::string> values = {
            {1, "I"},   {4, "IV"},  {5, "V"},    {9, "IX"},  {10, "X"},   {40, "XL"}, {50, "L"},
            {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
        int nums[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        int pos = 12;
        while (num != 0) {
            if (nums[pos] > num) {
                --pos;
            } else {
                romNum += values[nums[pos]];
                num -= nums[pos];
            }
        }
        return romNum;
    }
};
