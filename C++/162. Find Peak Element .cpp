162. Find Peak Element 
My Submissions QuestionEditorial Solution
Total Accepted: 61829 Total Submissions: 187770 Difficulty: Medium
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question



class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1 || (nums[0] > nums[1]))
            return 0;
        if(nums[nums.size() - 1] > nums[nums.size() - 2]) {
            return nums.size() - 1;
        }
        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                return i;
            }
        }
    }
};