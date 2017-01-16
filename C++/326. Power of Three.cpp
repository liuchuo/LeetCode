326. Power of Three 
My Submissions QuestionEditorial Solution
Total Accepted: 33438 Total Submissions: 92723 Difficulty: Easy
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        return pow(3, (round)(log(n) / log(3))) == n;
    }
};