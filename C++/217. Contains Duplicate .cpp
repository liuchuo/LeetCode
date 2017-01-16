217. Contains Duplicate 
My Submissions QuestionEditorial Solution
Total Accepted: 81618 Total Submissions: 199467 Difficulty: Easy
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> m;
        for(int i = 0; i < nums.size(); i++) {
            m.insert(nums[i]);
        }
        return nums.size() != m.size();
    }
};