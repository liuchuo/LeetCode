14. Longest Common Prefix
My Submissions QuestionEditorial Solution
Total Accepted: 96364 Total Submissions: 343735 Difficulty: Easy
Write a function to find the longest common prefix string amongst an array of strings.

Subscribe to see which companies asked this question


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string s = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            for(int j = 0; j < s.length(); j++) {
                if(s[j] != strs[i][j]) {
                    s = s.substr(0, j);
                    break;
                }
            }
        }
        return s;
    }
};