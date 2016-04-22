219. Contains Duplicate II 
My Submissions QuestionEditorial Solution
Total Accepted: 53942 Total Submissions: 181144 Difficulty: Easy
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

Subscribe to see which companies asked this question

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        int t = 0;
        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            if(s.size() == t) {
                for(int j = i - 1; j >= 0 && j >= i - k; j--) {
                    if(nums[i] == nums[j])
                        return true;
                }
            }
            t = s.size();
        }
        return false;
    }
};