80. Remove Duplicates from Sorted Array II 
My Submissions QuestionEditorial Solution
Total Accepted: 71707 Total Submissions: 220179 Difficulty: Medium
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It does not matter what you leave beyond the new length.

Subscribe to see which companies asked this question

Show Tags



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int len = 1;
        vector<int> v(nums.size());
        int cnt = 1;
        v[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            if(cnt <= 2) {
                v[len++] = nums[i];
            }
        }
        for(int i = 0; i < len; i++) {
            nums[i] = v[i];
        }
        return len;
    }
};