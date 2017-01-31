216. Combination Sum III
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

分析：一个dfs回溯解决，如果当前k == 0而且 n == 0说明一定达到了k个数，和为n，则将当前path压入result数组中；从start开始一直到9，分别压入path中深度优先搜索。深度优先搜索完了之后记得回溯path中pop出最后一个元素～
因为题目要求结果集合必须是按照集合顺序，也就是从小到大而且没有重复元素，那么就要设立一个start变量，每次for循环的时候从start开始，一开始start为0，每次规定start为i+1，即只能从当前数字的下一个数字开始，这样就能保证结果是递增无重复数字的集合序列～～

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return result;
    }
    
    void dfs(int k, int n, int start) {
        if(k == 0) {
            if(n == 0)
                result.push_back(path);
            return ;
        }
        for(int i = start; i <= 9; i++) {
            path.push_back(i);
            dfs(k - 1, n - i, i + 1);
            path.pop_back();
        }
    }
};