9. Palindrome Number 
My Submissions QuestionEditorial Solution
Total Accepted: 117710 Total Submissions: 374088 Difficulty: Easy
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.


Subscribe to see which companies asked this question


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int len = 1;
        while(x / len >= 10) {
            len = len * 10;
        }
        while(x) {
            int left = x / len;
            int right = x % 10;
            if(left != right) {
                return false;
            }
            x = x % len;
            x = x / 10;
            len = len / 100;
        }
        return true;
    }
};