695. Max Area of Island
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1’s (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.

题目大意：给一个地图，0表示水1表示陆地，计算最大的一个岛屿的面积～
分析：遍历所有grid[x][y] == 1的地盘，每次将tempcnt = 0，然后进行dfs，dfs中从4个方向遍历，每次对于grid[x][y] == 1的地盘进行更深一层的dfs，进入dfs先将当前地盘标记为0且tempcnt++，最后tempcnt的值即为这个岛屿的数量，当main函数中遍历过所有的岛屿后返回cnt的最大值即是面积最大的岛屿～

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        n = grid.size(), m = grid[0].size();
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (grid[x][y] == 1) {
                    tempcnt = 0;
                    dfs(x, y, grid);
                    cnt = max(cnt, tempcnt);
                }
            }
        }
        return cnt;
    }
private:
    int n, m, cnt = 0, tempcnt = 0;
    int arr[5] = {0, 1, 0, -1, 0};
    void dfs(int x, int y, vector<vector<int>>& grid) {
        grid[x][y] = 0;
        tempcnt++;
        for (int i = 0; i < 4; i++) {
            int tx = x + arr[i], ty = y + arr[i+1];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == 1)
                dfs(tx, ty, grid);
        }
    }
};