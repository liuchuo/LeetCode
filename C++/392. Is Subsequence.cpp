392. Is Subsequence
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

题目大意：判断s是否是t的子串～
分析：设立两个指针p和q，分别指向s[0]和t[0]，只要p和q没有超出s和t的长度范围，不断判断当前s[p]与t[q]是否相等，如果不相等就将q指针不断后移，直到相等为止～相等后p和q指针同时后移，依次判断～
最终判断p指针是否等于lens，即p指针是否指完了s字符串的所有字符～

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0, q = 0, lens = s.length(), lent = t.length();
        while(p < lens && q < lent) {
            while(q < lent && s[p] != t[q]) q++;
            if(s[p] == t[q]) {
                p++;
                q++;
            }
        }
        return p == lens;
    }
};