724. Find Pivot Index
Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:
Input: 
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation: 
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
Example 2:
Input: 
nums = [1, 2, 3]
Output: -1
Explanation: 
There is no index that satisfies the conditions in the problem statement.
Note:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].

题目大意：在一个数组中找到一个数字的下标，要求这个数字左边的数字和等于右边的数字和，如果不存在就返回-1
分析：计算数组所有元素和sum，然后遍历数组，每次将前i-1个数字的和累加在t中，每次从sum中减去nums[i]，这样sum就是nums[i]后面所有数字的和，如果sum == t就返回i，否则就返回-1

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), sum = 0, t = 0;
        if (n == 0) return -1;
        if (n == 1) return 0;
        for (int i : nums) sum += i;
        for (int i = 0; i < n; i++) {
            sum -= nums[i];
            if (sum == t) return i;
            t += nums[i];
        }
        return -1;
    }
};