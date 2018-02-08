521. Longest Uncommon Subsequence I
Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc"
Output: 3
Explanation: The longest uncommon subsequence is "aba" (or "cdc"), 
because "aba" is a subsequence of "aba", 
but not a subsequence of any other strings in the group of two strings. 
Note:

Both strings' lengths will not exceed 100.
Only letters from a ~ z will appear in input strings.

题目大意：给定两个字符串，找这两个字符串中最长非公共子序列。 最长的非公共子序列是指这些字符串之一的最长的子序列，并且这个子序列不是其他字符串的任何子序列。
分析：如果a和b相等，那么a的任意一个子串都是b的子串，反之同理，所以a和b相等时返回-1；如果a和b不相等，返回a和b长度中较长的数字，因为只要取a和b中长度较长的那个字符串，必然是另一方的最长非公共子串～

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.length(), b.length());
    }
};