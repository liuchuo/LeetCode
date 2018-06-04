377. Combination Sum IV
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

题目大意：给一个数组，都是正整数且没有重复的数字，任取里面的数字，问有多少种相加等于target的方式
分析：建立dp数组，（dp[i]表示相加等于i的方法有dp[i]个）设dp[0]等于1。i从1到target，给dp[i]赋值。要想知道dp[i]的值，用j遍历nums数组，只要将dp[i-nums[j]]的值累加即可得到，注意只累加i大于等于nums[j]的情况，表示让nums[j]作为第一个数字，剩下的数字有的组合方法有dp[i-nums[j]]个，最终返回dp[target]的值即可～

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
            for (int j = 0; j < nums.size(); j++)
                if (i >= nums[j]) dp[i] += dp[i - nums[j]];
        return dp[target];
    }
};