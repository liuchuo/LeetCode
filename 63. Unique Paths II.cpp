63. Unique Paths II 
My Submissions QuestionEditorial Solution
Total Accepted: 65522 Total Submissions: 222812 Difficulty: Medium
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

这道题是上一道题的升级版~加了障碍物~
加不加障碍物差别就在于，当当前地域有障碍物的时候，a[i][j] = 0
其余的不变：
0.a[0][0] = 1;
1.对于i==0的时候，为最上面一排，当前方格只能由左边方格来，所以a[i][j] = a[i][j-1];
2.对于j==0的时候，为最左边一排，当前方格只能由上边方格来，所以a[i][j] = a[i-1][j];
3.其余情况，当前方格能由左边和上边两个方向过来，所以a[i][j] = a[i-1][j] + a[i][j-1];
最后直到一直递推输出到终点(m-1, n-1)的时候return a[m-1][n-1];



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int a[100][100];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    a[i][j] = 0;
                } else if(i == 0 && j == 0) {
                    a[i][j] = 1;
                } else if(i == 0) {
                    a[i][j] = a[i][j-1];
                } else if(j == 0) {
                    a[i][j] = a[i-1][j];
                } else {
                    a[i][j] = a[i-1][j] + a[i][j-1];
                }
            }
        }
        return a[m-1][n-1];
    }
};