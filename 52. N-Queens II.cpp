52. N-Queens II
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.
分析：和LeetCode 51. N-Queens一样，只需改动几行代码即可~

class Solution {
    int cnt = 0;
public:
    int totalNQueens(int n) {
        vector<int> pos(n);
        dfs(pos, n, 0);
        return cnt;
    }
private:
    void dfs(vector<int> &pos, int n, int row) {
        if(row == n) {
            cnt++;
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