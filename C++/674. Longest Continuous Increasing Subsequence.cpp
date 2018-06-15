674. Longest Continuous Increasing Subsequence
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it is not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
Note: Length of the array will not exceed 10,000.

题目大意：给一个乱序数组，返回这个数组中递增连续子序列中最长的长度～
分析：遍历从i = 1到结尾，每次比较nums[i-1]和nums[i]，如果是递增的就将temp++，否则temp=1，每次将temp最大值保存在ans中，最后返回ans的值～

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int temp = 1, ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            temp = (nums[i-1] < nums[i]) ? temp + 1 : 1;
            ans = max(ans, temp);
        }
        return nums.size() == 0 ? 0 : ans;
    }
};