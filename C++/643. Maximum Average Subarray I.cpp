643. Maximum Average Subarray I
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].


题目大意：给定一个由n个整数组成的数组，找到具有最大平均值的给定长度k的连续子数组。你需要输出最大的平均值～
分析：sum[i]保存0～i个数字的和，每次将(sum[i]-sum[i-k])的最大值保存在ans中，然后返回ans*1.0/k

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0.0;
        vector<int> sum(nums.size());
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i-1] + nums[i];
            if (i >= k - 1) ans = max(ans, sum[i] - sum[i-k]);
        }
        return ans * 1.0 / k;       
    }
};