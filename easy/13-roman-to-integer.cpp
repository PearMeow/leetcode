/**
 * @file 13-roman-to-integer.cpp
 * @author Perry Huang
 * @date 2025-02-25
 * 13. Roman to Integer
 * Given a roman numeral, convert it to an integer.
 */

#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(const std::string& s) {
        int num = 0;
        std::unordered_map<char, int> values = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                                {'C', 100}, {'D', 500}, {'M', 1000}};
        for (size_t i = 0; i < s.size() - 1; ++i) {
            if ((s[i] == 'I') && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                num -= values['I'];
            } else if ((s[i] == 'X') && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                num -= values['X'];
            } else if ((s[i] == 'C') && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                num -= values['C'];
            } else
                num += values[s[i]];
        }
        num += values[s[s.size() - 1]];
        return num;
    }
};
