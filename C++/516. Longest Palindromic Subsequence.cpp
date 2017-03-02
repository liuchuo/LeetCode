516. Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".

题目大意：给一个字符串s，找最长回文子串～返回这个最长回文子串的长度～
分析：使用动态规划解决～设立一个len行len列的dp数组～dp[i][j]表示字符串i～j下标所构成的子串中最长回文子串的长度～最后我们需要返回的是dp[0][len-1]的值～
dp数组这样更新：首先i指针从尾到头遍历，j指针从i指针后面一个元素开始一直遍历到尾部～一开始dp[i][i]的值都为1，如果当前i和j所指元素相等，说明能够加到i～j的回文子串的长度中，所以更新dp[i][j] = dp[i+1][j-1] + 2; 如果当前元素不相等，那么说明这两个i、j所指元素对回文串无贡献，则dp[i][j]就是从dp[i+1][j]和dp[i][j-1]中选取较大的一个值即可～

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len));
        for (int i = len - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < len; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][len-1];
    }
    
};