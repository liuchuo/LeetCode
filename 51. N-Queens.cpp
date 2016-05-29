51. N-Queens
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
分析：pos[i]存放的是第i行的皇后所在的位置
递归以行的形式递归，每次放置的皇后要判断是否与前面已经放置的皇后冲突
从pos[row] = 0开始一直到n-1，判断是否安全 如果安全就进行下一行的摆放
每次递归到row==n的时候表示当前所有n个皇后已经摆放完成
此时将当前完成的结果保存在string类型的temp数组里面，先将数组置为'.....'
后根据pos[i]存放i行皇后的位置的特性将temp数组里面temp[i][pos[i]]置为'Q'
然后将temp压入v数组中，return。这样递归结束就能找到所有的摆放方法。
这是一个深度优先的过程，从在第一行放在第一个位置开始，摆放第二行、第三行...直到最后一行。
然后pos[row]++,表示将第一行放在第二个位置...然后摆放第二行、第三行...直到最后一行……
直到所有的情况深度优先搜索完成。

class Solution {
    vector<vector<string> > v;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> pos(n);
        dfs(pos, n, 0);
        return v;
    }
private:
    void dfs(vector<int> &pos, int n, int row) {
        if(row == n) {
            vector<string> temp(n, string(n, '.'));
            for(int i = 0; i < n; i++) {
                temp[i][pos[i]] = 'Q';
            }
            v.push_back(temp);
            return ;
        }
        for(pos[row] = 0; pos[row] < n; pos[row]++) {
            if(issafe(pos, n, row)) {
                dfs(pos, n, row + 1);
            }
        }
    }
    
    bool issafe(vector<int> &pos, int n, int row) {
        for(int i = 0; i < row; i++)
            if(pos[i] == pos[row] || abs(i - row) == abs(pos[i] - pos[row]))
                return false;
        return true;
    }
};