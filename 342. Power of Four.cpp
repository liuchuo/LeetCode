342. Power of Four
 My Submissions QuestionEditorial Solution
Total Accepted: 2459 Total Submissions: 7074 Difficulty: Easy
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

Credits:
Special thanks to @yukuairoy for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems


class Solution {
public:
    bool isPowerOfFour(int num) {
        return num <= 0 ? false : pow(4, (round)(log(num) / log(4))) == num;
    }
};
