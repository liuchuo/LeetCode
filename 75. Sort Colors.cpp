75. Sort Colors 
My Submissions QuestionEditorial Solution
Total Accepted: 94584 Total Submissions: 273580 Difficulty: Medium
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library’s sort function for this problem.

click to show follow up.

Subscribe to see which companies asked this question


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                cnt0++;
            } else if (nums[i] == 1) {
                cnt1++;
            } else {
                cnt2++;
            }
        }
        for(int i = 0; i < cnt0; i++) {
            nums[i] = 0;
        }
        for(int i = cnt0; i < cnt0 + cnt1; i++) {
            nums[i] = 1;
        }
        for(int i = cnt1 + cnt0; i < nums.size(); i++) {
            nums[i] = 2;
        }
    }
};