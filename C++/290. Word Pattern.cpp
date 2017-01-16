290. Word Pattern 
My Submissions QuestionEditorial Solution
Total Accepted: 33127 Total Submissions: 114634 Difficulty: Easy
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

Credits:
Special thanks to @minglotus6 for adding this problem and creating all test cases.

Subscribe to see which companies asked this question


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> ptos;
        map<string, char> stop;
        int len = pattern.length();
        string *s = new string [len];
        int cnt = 0;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == ' ')
                cnt++;
        }
        if(cnt != len - 1) {
            return false;
        }
        int t = 0;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] != ' ') {
                s[t] += str[i];
            } else {
                t++;
            }
        }
        for(int i = 0; i < len; i++) {
            if(ptos.find(pattern[i]) != ptos.end() && ptos[pattern[i]] != s[i]
            || stop.find(s[i]) != stop.end() && stop[s[i]] != pattern[i])
                return false;
            ptos[pattern[i]] = s[i];
            stop[s[i]] = pattern[i];
        }
        return true;
    }
};