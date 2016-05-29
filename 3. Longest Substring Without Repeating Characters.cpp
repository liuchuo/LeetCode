3. Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
分析：用两个指针ij从头开始遍历字符串。ij分别表示最长字串的首尾下标。如果第j个与i与j当中的某处k重复，那么只需i从k+1开始继续判断是否有重复的就好。当然，在i++一直到k的过程中，不要忘记把已经收录的字符存在标记为不存在。所以用一个book数组标记该字符在i~j当中是否出现过。每一次找到重复的字符的时候判断j-i是否比最大值大。一个特例是，如果i~j中一直让j到了最后一个字符都没有重复但是此时的j-i是最长的长度，所以要在return语句前再加上一句判断j-i的大小是否比当前maxlen大。


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, len = s.length();
        int maxlen = 0;
        int book[256] = {0};
        while(j < len) {
            if(book[s[j]] == 1) {
                maxlen = max(maxlen, j - i);
                while(s[i] != s[j]) {
                    book[s[i]] = 0;
                    i++;
                }
                i++;
            } else {
                book[s[j]] = 1;
            }
            j++;
        }
        maxlen = max(maxlen, j - i);
        return maxlen;
    }
};
