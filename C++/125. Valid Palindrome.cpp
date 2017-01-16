125. Valid Palindrome   
My Submissions QuestionEditorial Solution
Total Accepted: 99300 Total Submissions: 417275 Difficulty: Easy
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

Subscribe to see which companies asked this question


class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0)
            return true;
        int i = 0, j = s.length() - 1;
        while(i < j) {
            while(i < j && !isalnum(s[i])) {
                i++;
            }
            while(i < j && !isalnum(s[j])) {
                j--;
            }
            if(i < j && tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
};