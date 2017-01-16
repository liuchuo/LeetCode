263. Ugly Number 
My Submissions QuestionEditorial Solution
Total Accepted: 51161 Total Submissions: 140414 Difficulty: Easy
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) {
            return false;
        }
        int flag = 0;
        while(num != 1) {
            flag = 0;
            if(num % 2 == 0) {
                num = num / 2;
                flag = 1;
            }
            if(num % 3 == 0) {
                 num = num / 3;
                 flag = 1;
            }
            if(num % 5 == 0) {
                num = num / 5;
                flag = 1;
            }
            if(flag == 0) {
                return false;
            }
        }
        return true;
    }
};