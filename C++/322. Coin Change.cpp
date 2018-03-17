322. Coin Change
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

题目大意：你有一些不同面值的硬币，你需要用这些硬币凑成amount值，计算需要的最少的硬币个数～如果不能凑成，就返回-1
分析：设立dp数组（dp[i]表示凑成i需要的最小硬币个数），一开始dp[0]等于0，i从1到amount填充dp[i]的值，第二层循环遍历coins数组，假设coins[j]作为第一个硬币，那么dp[i-coins[j]]表示剩下的金额需要的硬币个数，此时判断i-coins[j]是否等于-1，也就是是否能够凑成，如果能够凑成，那么当dp[i]>0时表示凑成i需要dp[i]个硬币，这种情况下如果dp[i-coins[j]]+1更小，就更新dp[i]，否则就保留dp[i]的值。如果dp[i]本身就<=0说明前面没有方法可以凑成i，那么就直接更新dp[i]为dp[i-coins[j]] + 1的值，有一种凑成的方法总比没有好～最后返回dp[amount]的值表示凑成amount数量需要的最小硬币个数，如果不存在，本身dp数组的初值就为-1，所以也会按照要求返回-1～

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j] && dp[i-coins[j]] != -1) {
                    if (dp[i] > 0) 
                        dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                    else
                        dp[i] = dp[i-coins[j]] + 1;
                }
            }
        }
        return dp[amount];
    }
};