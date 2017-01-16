136. Single Number 
My Submissions QuestionEditorial Solution
Total Accepted: 123037 Total Submissions: 248977 Difficulty: Medium
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?



Subscribe to see which companies asked this question

update v2.0:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i = i + 2) {
            if(nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        return nums[nums.size() - 1];
    }
};



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> s;
        int t = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            s.insert(nums[i]);
            if(i % 2 == 1 && s.size() != t) {
                return nums[i - 1];
            }
            t = s.size();
        }
        return nums[nums.size() - 1];
    }
};

