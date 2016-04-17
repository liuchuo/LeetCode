202. Happy Number 
My Submissions QuestionEditorial Solution
Total Accepted: 63399 Total Submissions: 174727 Difficulty: Easy
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Credits:
Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question


//即使输入的数为9*10^10，也会在第一次 while 降到3位数，第二次 while 降到2位数，不超过10次肯定能知道是否满足题目条件
//所以加了一个 cnt 计数器 在超过10次就跳出循环说明不满足题意

class Solution {
public:
    bool isHappy(int n) {
        int cnt = 0;
        while(n != 1) {
            cnt++;
            int temp = 0;
            while(n) {
                temp = temp + (n % 10) * (n % 10);
                n = n / 10;
            }
            n = temp;
            if(cnt == 10) {
                return false;
            }
        }
        return true;
    }
};