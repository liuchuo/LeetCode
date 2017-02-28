504. Base 7
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].

题目大意：给一个整数，以字符串形式返回它的7进制～
分析：如果num等于0则直接return 0，如果num小于0则变为相反数，且标记sign为-，每次将对num 取余 7的结果插入result字符串的最前面，并将num / 7，最后返回sign + result的字符串结果～

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string sign = "";
        if (num < 0) {
            num = 0 - num;
            sign = "-";
        }
        string result = "";
        while (num != 0) {
            result = to_string(num % 7) + result;
            num = num / 7;
        }
        return sign + result;
    }
};