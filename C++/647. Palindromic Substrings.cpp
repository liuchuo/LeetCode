647. Palindromic Substrings
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won’t exceed 1000.

题目大意：给定一个字符串，计算这个字符串中有多少回文子串。（具有不同start下标或end下标的子字符串即使包含相同的字符也会被计为不同的子字符串。）
分析：对于s[i]来说，检测s[i-j]==s[i+j]是否成立，每一次相等就ans++、检测s[i-j-1]==s[i+j]是否成立，每次成立就ans++，最后返回ans的值～

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            for (int j = 0; i + j < n && i - j >= 0 && s[i-j] == s[i+j]; j++) ans++;
            for (int j = 0; i + j < n && i - j - 1 >=0 && s[i-j-1] == s[i+j]; j++) ans++;
        }
        return ans;
    }
};
