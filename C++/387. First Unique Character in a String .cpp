387. First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

Subscribe to see which companies asked this question

分析：map存储每个字符的出现次数，从头遍历数组return第一个m[s[i]] == 1的下标。如果没有就return -1。
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> m;
        for(int i = 0; i < s.length(); i++)
            m[s[i]]++;
        for(int i = 0; i < s.length(); i++) {
            if(m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};