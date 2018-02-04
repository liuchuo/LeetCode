200. Number of Islands
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

题目大意：给一个地图，0表示水，1表示陆地，计算陆地的个数
分析：计算连通分量的个数，每次遍历是陆地(grid[x][y] == 1)的区域，dfs中从4个方向遍历，每次将访问过的grid标记为'0'，main函数中进入dfs多少次就表示有多少个岛屿（也就是有多少个连通分量的个数）

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        n = grid.size(), m = grid[0].size();
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (grid[x][y] == '1') {
                    dfs(x, y, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
private:
    int n, m, cnt = 0;
    int arr[5] = {1, 0, -1, 0, 1};
    void dfs(int x, int y, vector<vector<char>>& grid) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int tx = x + arr[i], ty = y + arr[i+1];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == '1')
                dfs(tx, ty, grid);
        }
    }
};