462. Minimum Moves to Equal Array Elements II
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

题目大意：给一个非空整数数组，每次可以将数组中一个元素+1或者-1，求最少需要多少次这样的操作，才能使数组中所有的数都想等～
分析：让所有数都等于那个第n/2大的数字～首先用nth_element(nums.begin(), nums.begin() + n / 2, nums.end());将第n/2大的数字放到最中间，然后取得它的值为mid，最后遍历数组，累加所有元素与mid的差的绝对值即为所求～

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int result = 0, n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = *(nums.begin() + n / 2);
        for(int i = 0; i < n; i++)
            result += abs(nums[i] - mid);
        return result;
    }
};