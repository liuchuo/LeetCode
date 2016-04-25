238. Product of Array Except Self 
My Submissions QuestionEditorial Solution
Total Accepted: 41121 Total Submissions: 96992 Difficulty: Medium
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

Subscribe to see which companies asked this question



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v(nums.size());
        int right = 1;
        v[0] = 1;
        //左边所有数字的乘积
        for(int i = 1; i < nums.size(); i++) {
           v[i] = nums[i - 1] * v[i - 1]; 
        }
        for(int i = nums.size() - 2; i >= 0; i--) {
            right = right * nums[i + 1];
            v[i] = v[i] * right;
        }
        return v;
    }
};