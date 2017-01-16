268. Missing Number 
My Submissions QuestionEditorial Solution
Total Accepted: 46506 Total Submissions: 116644 Difficulty: Medium
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int *book = new int [nums.size() + 1];
        for(int i = 0; i <= nums.size(); i++) {
            book[i] = 0;
        }
        for(int i = 0; i < nums.size(); i++) {
            book[nums[i]] = 1;
        }
        for(int i = 0; i <= nums.size(); i++) {
            if(book[i] == 0) {
                return i;
            }
        }
    }
};