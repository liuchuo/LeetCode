16. 3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

题目大意：给定一个整型数组，在数组中找xyz，使x+y+z最接近target，返回最接近的x+y+z的值～
分析：对nums排序，先确定第一个数为nums[i], 使begin = i + 1，end = n - 1,如果当前sum == target，就令begin++，end--，指针分别向前向后移动一个，如果sum比较大，就令end往前一个；如果sum比较小，就令begin往后一个～每次根据sum更新result的值，result设置为long型，避免一开始是INT最大值、加了负数后溢出～

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long result = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            int begin = i + 1, end = n - 1;
            while(begin < end) {
                int sum = nums[i] + nums[begin] + nums[end];
                if(sum == target) {
                    begin++;
                    end--;
                } else if(sum > target) {
                    end--;
                } else {
                    begin++;
                }
                if(abs(sum - target) < abs(result - target))
                    result = sum;
            }
        }
        return (int)result;
    }
};