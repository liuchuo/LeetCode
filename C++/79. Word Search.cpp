79. Word Search
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

题目大意：给一个char型二维数组和一个word字符串，寻找网格中是否含有word字符串，只能通过相邻（垂直或者水平）的格子连接～
分析：对于二维数组中的每一个点都开始遍历，如果当前点的字母正好等于word[0]就进入dfs，设立flag标记是否找到，设立visit标记是否访问：
首先令起始节点visit[j][k]标记为已经访问过，接着dfs，如果flag为true直接return，如果当前index正好为word的最后一个字符下标就标记flag为true，return。
从四个方向开始对结点进行深度优先搜索，首先要保证搜索的结点满足：1.是合法的在网格之内的 2.未被访问过 3.当前字符与要找的word[index+1]相同。满足则标记visit[tx][ty] = true,且dfs tx和ty以及index+1，两个dfs后要把他重新置为false～
这样最后返回flag的值即为是否能找到的结果～

class Solution {
private:
    bool flag = false;
    vector<vector<bool>> visit;
    vector<vector<char>> board;
    string word = "";
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return word == "";
        m = board.size(), n = board[0].size();
        this->word = word;
        this->board = board;
        visit.resize(m, vector<bool>(n));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (board[j][k] == word[0]) {
                    visit[j][k] = true;
                    dfs(j, k, 0);
                    visit[j][k] = false;
                }
            }
        }
        return flag;
    }
    
    void dfs(int x, int y, int index) {
        if (flag == true) return ;
        if (index == word.length() - 1) {
            flag = true;
            return ;
        }
        for (int i = 0; i < 4; i++) {
            int tx = x + dir[i][0], ty = y + dir[i][1];
            if (tx >= 0 && tx < m && ty >= 0 && ty < n && board[tx][ty] == word[index + 1] && visit[tx][ty] == false) {
                visit[tx][ty] = true;
                dfs(tx, ty, index + 1);
                visit[tx][ty] = false;
            }
        }
    }
};