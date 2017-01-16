137. Single Number II 
My Submissions QuestionEditorial Solution
Total Accepted: 80394 Total Submissions: 214787 Difficulty: Medium
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size() - 4; i = i + 3) {
            if(nums[i] != nums[i + 2]) {
                return nums[i];
            }
        }
        return nums[nums.size() - 1];
    }
};
