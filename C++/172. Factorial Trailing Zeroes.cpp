172. Factorial Trailing Zeroes 
My Submissions QuestionEditorial Solution
Total Accepted: 55895 Total Submissions: 171950 Difficulty: Easy
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
在logn的时间内 找到n！末尾有几个零

//5*2 = 10出现一个0，n*(n-1)*(n-2)...1当中能被5整除的数少于能被2整除的数
//所以能被5整除的5的个数就是0的个数
//比如25！,25 = 5 * 5有两个5，20，15，10，5各含一个5，这六个5分别和2结合相乘就能得到末尾6个0
//所以只要count每个因子中5的个数就行

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n != 0) {
            cnt = cnt + n / 5;
            n = n / 5;
        }
        return cnt;
    }
};