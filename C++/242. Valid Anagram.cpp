242. Valid Anagram 
My Submissions QuestionEditorial Solution
Total Accepted: 73035 Total Submissions: 175966 Difficulty: Easy
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

Subscribe to see which companies asked this question

class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {0};
        if(s.length() != t.length())
            return 0;
        for(int i = 0; i < s.length(); i++) {
            a[s[i] - 'a']++;
        }
        for(int i = 0; i < t.length(); i++) {
            a[t[i] -'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(a[i] != 0) {
                return 0;
            }
        }
        return 1;
    }
};