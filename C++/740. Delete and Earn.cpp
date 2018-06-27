740. Delete and Earn
Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:
Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.
Example 2:
Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation: 
Delete 3 to earn 3 points, deleting both 2 and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
Note:

The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].

题目大意：给一个数组，你可以拿起nums[i]并且删除nums[i]并得到nums[i]分数，但是你必须删除nums[i]-1和nums[i]+1。求问你能够获得最大的分数会是多少～
分析：数组不是有序的，且在1～10000之间，所以先遍历数组，将i数字所拥有的个数保存在cnt[i]中。设立dp数组，含有10001个元素，（dp[i]表示遍历到i这个数的时候当前情况下的最大值。最后返回dp[10000]的值就是所求），dp[0] = 0, dp[1] = cnt[1]。i从2遍历到10000。对于dp[i]，因为如果要了i这个数就不能要i-1和i+1，所以当前i有两个选择：一，要i这个数带来的分数cnt[i] * i，那就不能要dp[i-1]只能要dp[i-2]。二，不要i带来的分数要dp[i-1]的分数。这两个选择取最大值，所以dp[i] = max(dp[i-1], cnt[i] * i + dp[i-2])，最后返回dp[10000]～

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> cnt(10001, 0), dp(10001, 0);
        for (int i = 0; i < n; i++) cnt[nums[i]]++;
        dp[1] = cnt[1];
        for (int i = 2; i <= 10000; i++)
            dp[i] = max(dp[i-1], cnt[i] * i + dp[i-2]);
        return dp[10000];
    }
};