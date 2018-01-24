40. Combination Sum II
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

题目大意：给一个集合的数字，和一个目标数字target，找一种组合方式使组合中所有数字之和等于target，集合中每个数字只能使用一次，集合中每个数字都是正数～
分析：先对所有数字排序，之后按照深度优先搜索将index + 1 ～ len之间所有的数字都尝试放在结果集中，比较sum与target的大小，如果和target一样大，就把当前组合结果放入集合中（为了避免重复），如果比target大，因为所有数都是正数，所以要提前return（不这样做会超时的～）最后把集合中的所有结果放入一个二维数组result中，返回result～

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        nums = candidates;
        this->target = target;
        dfs(-1, 0);
        vector<vector<int>> result;
        for (auto it = s.begin(); it != s.end(); it++)
            result.push_back(*it);
        return result;
    }
private:
    vector<int> nums;
    int target;
    set<vector<int>> s;
    vector<int> row;
    void dfs(int index, int sum) {
        if (sum == target) {
            s.insert(row);
            return;
        } else if (sum > target) {
            return;
        }
        for (int i = index + 1; i < nums.size(); i++) {
            row.push_back(nums[i]);
            dfs(i, sum + nums[i]);
            row.pop_back();
        }
    }
};