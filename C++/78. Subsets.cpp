78. Subsets
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

题目大意：给一个集合nums，求nums的所有子集集合～
分析：用位运算，j从0到maxn变化，每一次计算j移动i位后最后一位是否为1，如果为1就将nums[i]的值放入result[j]～

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        int maxn = pow(2, len);
        vector<vector<int>> result(maxn);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < maxn; j++) {
                if ((j >> i) & 1)
                    result[j].push_back(nums[i]);
            }
        }
        return result;
    }
};