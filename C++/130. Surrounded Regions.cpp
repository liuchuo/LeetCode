130. Surrounded Regions
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X

题目大意：给一个地图，X表示围墙，找出所有被X围墙包围的O，并且把被包围的O替换成X～
分析：我的方法是与其找被包围的O，不如反过来寻找没有被包围的O～
从地图的外围一圈开始寻找～如果当前位置是O～那就找他的上下左右～把与这个O联通的所有O都标记为"*"～
标记为*后，所有没有被标记为*的O就是被包围的O～那就将所有剩余的O标记为X，把所有*标记为O～返回这张地图就可以了～

class Solution {
private:
    int m, n;
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return ;
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            dfs(i, 0, board);
            dfs(i, n - 1, board);
        }
        for(int j = 0; j < n; j++) {
            dfs(0, j, board);
            dfs(m - 1, j, board);
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '*')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    void dfs(int row, int col, vector<vector<char>>& board) {
        if(board[row][col] != 'O') return;
        board[row][col] = '*';
        if(row - 1 > 0) dfs(row - 1, col, board);
        if(col - 1 > 0) dfs(row, col - 1, board);
        if(row + 1 < m) dfs(row + 1, col, board);
        if(col + 1 < n) dfs(row, col + 1, board);
    }
};