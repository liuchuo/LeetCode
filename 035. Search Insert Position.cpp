35. Search Insert Position 
My Submissions QuestionEditorial Solution
Total Accepted: 101847 Total Submissions: 273775 Difficulty: Medium
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= target) {
                return i;
            }
            if(i == nums.size() - 1) {
                return nums.size();
            }
        }
    }
};


