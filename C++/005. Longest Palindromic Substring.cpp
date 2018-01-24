5. Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

题目大意：给一个字符串，找它的回文子串中长度最长的一个子串～
分析：首先令result为第一个元素，如果没有第一个元素就返回空字串，遍历字串，对于每个元素都从中间向两边寻找是否有回文子串，返回这个子串，将它的长度与result比较，如果比result长就更新result～
要分为奇数还是偶数考虑，奇数就左右都是i，偶数就是左边是i右边是i+1然后扩展～

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0) return "";
        string result = s.substr(0, 1);
        for (int i = 0; i <= len - 2; i++) {
            string temp = midToSide(s, i, i);
            if (temp.length() > result.length())
                result = temp;
            temp = midToSide(s, i, i + 1);
            if (temp.length() > result.length())
                result = temp;
        }
        return result;
    }
    
    string midToSide(string s, int left, int right) {
        while (left >= 0 && right <= s.length() - 1 && s[left] == s[right]) {
            left--; 
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};