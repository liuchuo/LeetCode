581. Shortest Unsorted Continuous Subarray
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

题目大意：给定一个整数数组，你需要找到一个连续的子数组，如果你按升序对这个子数组排序，那么整个数组将也是升序。你需要找到最短的这样的子数组并输出它的长度。
分析：对v排序，i找到第一个和排序后的数组v不相等的元素，j找到最后一个和排序后的数组v不相等的元素，如果i<=j说明存在这样一个长度，长度为j-i+1，否则不存在这样一个长度，则返回0

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v(nums);
        sort(v.begin(), v.end());
        int i = 0, j = nums.size() - 1;
        while (i < nums.size() && nums[i] == v[i]) i++;
        while (j >= 0 && nums[j] == v[j]) j--;
        return i <= j ? j - i + 1 : 0;
    }
};