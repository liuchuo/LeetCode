90. Subsets II
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

题目大意：给一个集合nums，nums中可能含有重复元素，求nums的所有子集集合～集合中的元素不能重复～
分析：首先对nums进行排序，接着用位运算，j从0到maxn变化，每一次计算j移动i位后最后一位是否为1，如果为1就将nums[i]的值放入result[j]～为了保证不重复，将result的结果放入集合s中，然后将s中的结果再放入result数组中返回～

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int maxn = pow(2, len);
        vector<vector<int>> result(maxn);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < maxn; j++) {
                if ((j >> i) & 1)
                    result[j].push_back(nums[i]);
            }
        }
        set<vector<int>> s;
        for (int i = 0; i < result.size(); i++)
            s.insert(result[i]);
        result.resize(0);
        for (auto it = s.begin(); it != s.end(); it++)
            result.push_back(*it);
        return result;
    }
};