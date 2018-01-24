77. Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

题目大意：给两个整数n和k，返回所有的k个数字组合，这些数字只能从1...n中选择～
分析：从cur == 0，cnt == 0开始，每次将cur + 1 ～ n之间的数字放入row中，并将cnt + 1，然后继续深度优先搜索直到cnt == k为止将row放入result中作为结果之一，不要忘记dfs遍历后还要将当前元素pop_back()出来，最后返回result～

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n, this->k = k;
        dfs(0, 0);
        return result;
    }
private:
    int n, k;
    vector<vector<int>> result;
    vector<int> row;
    void dfs(int cur, int cnt) {
        if (cnt == k) {
            result.push_back(row);
            return;
        }
        for (int i = cur + 1; i <= n; i++) {
            row.push_back(i);
            dfs(i, cnt + 1);
            row.pop_back();
        }
    }
};