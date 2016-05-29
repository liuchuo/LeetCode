58. Length of Last Word 
My Submissions QuestionEditorial Solution
Total Accepted: 90032 Total Submissions: 308380 Difficulty: Easy
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

Subscribe to see which companies asked this question



class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int flag = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(flag == 0 && s[i] == ' ') {
                continue;
            }
            if(s[i] != ' ') {
                flag = 1;
                cnt++;
            } else {
                break;
            }
        }
        return cnt;
    }
};