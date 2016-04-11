13. Roman to Integer 
My Submissions QuestionEditorial Solution
Total Accepted: 80246 Total Submissions: 205709 Difficulty: Easy
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Subscribe to see which companies asked this question

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char, int> m;
        char c[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int t[] = {1, 5, 10, 50, 100, 500, 1000};
        for(int i = 0; i < 7; i++) {
            m.insert(pair<char, int> (c[i], t[i]));
        }
        for(int i = 0; i < s.length() - 1; i++) {
            if(m[s[i]] >= m[s[i + 1]]) {
                ans = ans + m[s[i]];
            } else {
                ans = ans - m[s[i]];
            }
        }
        ans = ans + m[s[s.length() - 1]];
        return ans;
    }
};