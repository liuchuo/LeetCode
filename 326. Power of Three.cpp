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

//记住考虑特殊条件 n <= 0 。。否则会超时。。
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        while(n != 1) {
            if(n % 3 == 0) {
                n = n / 3;
            } else {
                return false;
            }
        }
        return true;
    }
};
