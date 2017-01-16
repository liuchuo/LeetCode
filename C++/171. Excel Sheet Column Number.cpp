171. Excel Sheet Column Number 
My Submissions QuestionEditorial Solution
Total Accepted: 73689 Total Submissions: 178744 Difficulty: Easy
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems


class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
              ans = ans*26 + s[i] - 'A' + 1;
        }
        return ans;
    }
};