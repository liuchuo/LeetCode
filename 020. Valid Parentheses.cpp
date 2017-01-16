20. Valid Parentheses 
My Submissions QuestionEditorial Solution
Total Accepted: 103858 Total Submissions: 355021 Difficulty: Easy
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Subscribe to see which companies asked this question


class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                t.push(s[i]);
            } else if(s[i] == ')') {
                if(i == 0 ||  t.empty() || t.top() != '(') {
                    return false;
                }
                t.pop();
            } else if(s[i] == ']') {
                if(i == 0 || t.empty() || t.top() != '[') {
                    return false;
                }
                t.pop();
            } else if(s[i] == '}') {
                if(i == 0 || t.empty() || t.top() != '{') {
                    return false;
                }
                t.pop();
            }
        }
        return t.empty();
    }
};