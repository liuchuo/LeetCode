463. Island Perimeter
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16

分析：如果彼此不相连，那么一个1就应该有4条边；考虑相连的情况，为了避免重复计算，只取每个为1的坐标的左边和上边：
如果当前点为1而且它上面也为1，他们彼此相连导致双方都失去1条边，也就是2条边；同理如果当前点为1它左边也为1，他们彼此相连导致双方都失去1条边，也就是2条边。不考虑第一行没有上一行和第一列没有左边的情况，则可以遍历每一个格子得到cnt

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    cnt += 4;
                    if(i != 0 && grid[i-1][j] == 1)
                        cnt -= 2;
                    if(j != 0 && grid[i][j-1] == 1)
                        cnt -= 2;
                }
            }
        }
        return cnt;
    }
};