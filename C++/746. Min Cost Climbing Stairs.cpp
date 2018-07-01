746. Min Cost Climbing Stairs
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].

题目大意：爬n阶的楼梯，每层都有一个cost值（0～n-1），每次可以爬1层或者2层，求爬完全程的最小花费cost（可以从第0层开始也可以从第1层开始）
分析：dp数组，每次dp[i] = cost[i] + min(dp[i-1], dp[i-2])，最终返回dp[n-1]和dp[n-2]中较小的那个～

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i = 2; i < n; i++)
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        return min(dp[n-1], dp[n-2]);
    }
};