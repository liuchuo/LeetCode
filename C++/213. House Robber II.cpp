213. House Robber II   
My Submissions QuestionEditorial Solution
Total Accepted: 27976 Total Submissions: 91078 Difficulty: Medium
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

这题是上一题House Robber的升级版~~新加了环形的街道biu biu biu~~
所以就会考虑到，最后一个和第一个房子是不能够同时进入的~要不然会告诉警察叔叔~~
所以分为两种情况~
0.不包括最后一个屋子~就抢劫0~n-2号屋子~
1.不包括第一个屋子~就抢劫1~n-1号屋子~
这样的话，return上面两种情况的最大值就好了~调用两次子函数求值，主函数取其最大值返回~

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        return max(func(nums, 0, n-2), func(nums, 1, n-1));
    }
    int func(vector<int>& nums, int begin, int end) {
        int n = end - begin + 1;
        vector<int> dp(n);
        dp[0] = nums[begin];
        dp[1] = max(nums[begin], nums[begin+1]);
        for(int i = 2; i < n; i++) {
            int temp = dp[i - 2] + nums[begin+i];
            dp[i] = max(temp, dp[i-1]);
        }
        return dp[n - 1];
    }
};