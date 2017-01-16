260. Single Number III 
My Submissions QuestionEditorial Solution
Total Accepted: 30707 Total Submissions: 70737 Difficulty: Medium
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v(2);
        int flag = 0;
        for(int i = 0; i < nums.size() - 1; i = i + 2) {
            if(nums[i] != nums[i + 1]) {
                v[0] = nums[i];
                for(int j = i + 1; j < nums.size() - 1; j = j + 2) {
                    if(nums[j] != nums[j + 1]) {
                        v[1] = nums[j];
                        flag = 1;
                        break;
                    }
                }
                break;
            }
        }
        if(flag == 0) {
            v[1] = nums[nums.size() - 1];
        }
        return v;
    }
};