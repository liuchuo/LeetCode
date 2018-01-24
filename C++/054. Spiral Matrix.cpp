54. Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
题目大意：给一个m*n的矩阵，以顺时针旋转的方式返回所有的元素到一个数组中～
分析：按照一个个矩阵的边框输出：x、m为行的上下界，y、n为列的上下界，每次输出这个围成的矩阵的第一行——最后一列——最后一行——第一列，然后将x和y自增1，m和n自减1～
注意：为了避免重复输出，当x和m相等或者y和n相等的时候，就输出一次第一行和最后一列就可以，不用重复输出最后一行和第一列～

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        for (int x = 0, y = 0; x <= m && y <= n; x++, y++, m--, n--) {
            for (int j = y; j <= n; j++)
                result.push_back(matrix[x][j]);
            for (int i = x + 1; i <= m - 1; i++)
                result.push_back(matrix[i][n]);
            for (int j = n; j >= y && x != m; j--)
                result.push_back(matrix[m][j]);
            for (int i = m - 1; i > x && y != n; i--)
                result.push_back(matrix[i][y]);
        }
        return result;
    }
};