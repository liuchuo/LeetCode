152. Maximum Product Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

题目大意：给一个整型数组，求该数组中所有连续子数组的元素乘积的最大值～
分析：需要保存临时最大值和最小值，因为最大值乘以一个正数可能构成新的最大值，而最小值乘以负数也可能构成新的最大值。
result是要求的结果，maxValue为nums[i]之前的，和nums[i]相邻的乘积的最大值，minValue为nums[i]之前的，和nums[i]相邻的乘积的最小值。
首先令result、maxValue和minValue都为nums[0], i从nums[1]开始一直到结束，tempMax为考虑是否选择之前的maxValue与nums[i]相乘，如果相乘结果更大就保留，否则就选择nums[i]本身为最大。tempMin同理～
然后maxValue和minValue比较tempMax/tempMin与minValue * nums[i]的大小关系，maxValue取较大值，minValue取较小值～
而result是取所有maxValue中的最大值～最后返回result～

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int result = nums[0], maxValue = nums[0], minValue = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tempMax = max(nums[i], maxValue * nums[i]);
            int tempMin = min(nums[i], maxValue * nums[i]);
            maxValue = max(tempMax, minValue * nums[i]);
            minValue = min(tempMin, minValue * nums[i]);
            result = max(maxValue, result);
        }
        return result;
    }
};