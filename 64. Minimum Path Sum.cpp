64. Minimum Path Sum   
My Submissions QuestionEditorial Solution
Total Accepted: 70363 Total Submissions: 201529 Difficulty: Medium
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Subscribe to see which companies asked this question

用一个dp二维数组标记当前方格的最小值~
0.当i == 0 && j == 0的时候，dp[i][j] = grid[i][j];
1.对于i==0的时候，为最上面一排，当前方格只能由左边方格来，所以dp[i][j] = dp[i][j-1] + grid[i][j];
2.对于j==0的时候，为最左边一排，当前方格只能由上边方格来，所以dp[i][j] = dp[i-1][j] + grid[i][j];
3.其他情况下，dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
最后直到一直递推输出到终点(m-1, n-1)的时候return dp[m-1][n-1];~~~~~

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else if(i == 0) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                } else if(j == 0) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
