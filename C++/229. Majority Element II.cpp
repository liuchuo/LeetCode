229. Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

Hint:

How many majority elements could it possibly have?


分析：用的常规做法，map计算每个数出现的次数，超过n/3的就放到集合里面，最后遍历集合放入数组中～

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        set<int> s;
        map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            m[nums[i]]++;
            if(m[nums[i]] > n / 3)
                s.insert(nums[i]);
        }
        for(auto it = s.begin(); it != s.end(); it++)
            result.push_back(*it);
        return result;
    }
};