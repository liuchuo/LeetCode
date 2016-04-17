205. Isomorphic Strings 
My Submissions QuestionEditorial Solution
Total Accepted: 53593 Total Submissions: 182404 Difficulty: Easy
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

Subscribe to see which companies asked this question


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        int lent = t.length();
        if(len != lent)
            return false;
        map<char, char> stot;
        map<char, char> ttos;
        for(int i = 0; i < len; i++) {
            if(stot.find(s[i]) != stot.end() && stot[s[i]] != t[i] 
            || ttos.find(t[i]) != ttos.end() && ttos[t[i]] != s[i])
                return false;
            stot[s[i]] = t[i];
            ttos[t[i]] = s[i];
        }
        return true;
    }
};