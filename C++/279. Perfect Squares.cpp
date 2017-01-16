279. Perfect Squares
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
分析：建立一个n+1长度的数组dp，dp[i]表示i这个数构成平方和需要数字的最小个数。
当j*j<i的时候，temp中保存j从1开始每加1得到的dp[i-j*j] + 1的最小值
当j*j=i的时候，dp[i]的值就直接为1
从2一直到n可以计算出dp[i]的所有值。。
最后return dp[n]的值。

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            int temp = 99999999;
            for(int j = 1; j * j <= i; j++) {
                if(j * j == i) {
                    temp = 1;
                    break;
                }
                temp = min(temp, dp[i-j*j] + 1);
            }
            dp[i] = temp;
        }
        return dp[n];
    }
};