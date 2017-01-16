62. Unique Paths 
My Submissions QuestionEditorial Solution
Total Accepted: 84185 Total Submissions: 233521 Difficulty: Medium
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Subscribe to see which companies asked this question


class Solution {
public:
    int uniquePaths(int m, int n) {
        int a[100][100];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0)
                    a[i][j] = 1;
                else
                    a[i][j] = a[i - 1][j] + a[i][j - 1];
            }
        }
        return a[m - 1][n - 1];
    }
};