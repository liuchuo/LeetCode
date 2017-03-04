525. Contiguous Array
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

题目大意：给一个二进制数组，找最长的连续子数组，要求子数组里面的0和1的个数相等～
分析：0和1数组，可以考虑把0换成-1，变成-1和0数组，那么本质上就是找是否有下标从i～j的总和为0的子数组～
令map保存sum和sum对应的下标的值，遍历数组每次计算数组当前的sum，如果当前sum之前已经出现过，比如说之前有过一个sum = 2，现在又sum = 2了，说明在第一次sum等于2的时候，它前面所有元素加起来总和是2，那么在它前面去掉2个元素1就能满足0，同理当前的sum = 2也可以通过去掉最前面的2个元素1使sum = 0，所以看看i - m[sum]是否比之前的最大值大，如果比之前最大值大就更新最大值～

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 0) nums[i] = -1;
        map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (m.find(sum) != m.end())
                result = max(result, i - m[sum]);
            else
                m[sum] = i;
        }
        return result;
    }
};