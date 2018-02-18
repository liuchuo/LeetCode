541. Reverse String II
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]

题目大意：给一个字符串s和一个整数k，每2k长度倒置前k个字符串，如果最后剩余的长度小于k则全都倒置，否则如果剩余的长度大于k小于2k，倒置前k个，返回倒置后的字符串～
分析：遍历字符串，步长为2k，每次倒置s.begin() + i～s.begin() + i + k的字符串，如果i + k > s.length()就倒置s.begin() + i～s.begin() + s.length()即可～O(∩_∩)O～

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i+=2*k) {
            int t = min((i + k), (int)s.length());
            reverse(s.begin() + i, s.begin() + t);
        }
        return s;
    }
};