409. Longest Palindrome
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

分析：统计每个字母出现的字数，如果是偶数就能放到回文串里；如果是奇数就只能hash[i] - 1个放到回文串里面，而且如果存在是奇数个数的字母，则最后可以加1，也就是把落单的字母中的任意一个放到回文串的最中间使长度加1～

class Solution {
public:
    int longestPalindrome(string s) {
        int hash[256] = {0}, len = 0, flag = 0;
        for(int i = 0; i < s.length(); i++)
            hash[s[i]]++;
        for(int i = 0; i < 256; i++) {
            if(hash[i] % 2 == 0) {
                len += hash[i];
            } else {
                len += (hash[i] - 1);
                flag = 1;
            }
        }
        return len + flag;
    }
};