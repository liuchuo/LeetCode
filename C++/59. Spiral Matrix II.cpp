59. Spiral Matrix II
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

题目大意：给一个n，输出一个n*n的数组，并且按照螺旋的方式填充入数字1～n*n。
分析：按照一个个矩阵的边框输入：x为矩阵的上界，n为矩阵的上界，每次输出这个围成的矩阵的第一行——最后一列——最后一行——第一列，然后将x自增1，m自减1～
注意：为了避免重复输出，当x和n相等的时候，就输入一次第一行和最后一列就可以，不用重复输入最后一行和第一列～

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        n = n - 1;
        int num = 1;
        for (int x = 0; x <= n; x++, n--) {
            for (int j = x; j <= n; j++)
                result[x][j] = num++;
            for (int i = x + 1; i <= n - 1; i++)
                result[i][n] = num++;
            for (int j = n; j >= x && x != n; j--)
                result[n][j] = num++;
            for (int i = n - 1; i >= x + 1 && x != n; i--)
                result[i][x] = num++;
        }
        return result;
    }
};