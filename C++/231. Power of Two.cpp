231. Power of Two 
My Submissions QuestionEditorial Solution
Total Accepted: 66387 Total Submissions: 183626 Difficulty: Easy
Given an integer, write a function to determine if it is a power of two.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question


update v2.0:
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        return pow(2, (round)(log(n) / log(2))) == n;
    }
};

//如果没有考虑n <= 0就会超时。。
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        while(n != 1) {
            if(n % 2 == 0) {
                n = n / 2;
            } else {
                return false;
            }
        }
        return true;
    }
};