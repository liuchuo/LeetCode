459. Repeated Substring Pattern
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

分析：设字串长度为len，字符串长度为slen，len从1开始一直到slen / 2遍历，如果slen % len != 0肯定当前len不符合，直接continue；否则将每一个长度为len的字串取出到sub2，比较与sub1是否相等，如果所有的都相等说明满足条件，return true，如果到最后循环结束后依旧没有找到这样一个len满足条件，则return false

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int slen = str.length();
        for(int len = 1; len <= slen / 2; len++) {
            if(slen % len != 0)
                continue;
            string sub1 = str.substr(0, len);
            int flag = 0;
            for(int i = len; i < slen; i += len) {
                string sub2 = str.substr(i, len);
                if(sub1 != sub2) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                return true;
        }
        return false;
    }
};