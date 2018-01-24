39. Combination Sum
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]

题目大意：给一个可选数的集合，和一个目标数target，找所有组合方式，使组合的数总和为target～集合中的数可以重复选择～
分析：深度优先搜索，每次i从index到len分别将i放入row中，如果index超过了nums的长度就return，如果sum == target就将当前结果放入result数组中，为了避免无底洞，如果重复加自己的时候（i == index的时候）考虑如果nums[i]是正数且sum 大于 target就别继续加了,直接return终止了这条路径～nums[i]是负数且sum < target的时候同理～最后返回result～

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        nums = candidates;
        this->target = target;
        dfs(0, 0);
        return result;
    }
private:
    vector<int> nums;
    int target;
    vector<vector<int>> result;
    vector<int> row;
    void dfs(int index, int sum) {
        if (index > nums.size() - 1) return;
        if (sum == target) result.push_back(row);
        for (int i = index; i < nums.size(); i++) {
            if (i == index && (nums[i] > 0 && sum > target || nums[i] < 0 && sum < target)) return;
            row.push_back(nums[i]);
            dfs(i, sum + nums[i]);
            row.pop_back();
        }
    }
};