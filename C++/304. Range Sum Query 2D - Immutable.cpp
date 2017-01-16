304. Range Sum Query 2D - Immutable
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Example:
Given matrix = [
[3, 0, 1, 4, 2],
[5, 6, 3, 2, 1],
[1, 2, 0, 1, 5],
[4, 1, 0, 1, 7],
[1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
啊喂，不要看下面代码这么长就关闭页面啊。。。。逻辑还是十分简明清晰的。。。
先用一个和方阵一样大小的方阵存储入所有它的左上角所有方块上数字的总和~~
然后每次调用只要大方块减去两个多余的小方块再加上重复减去的小方块就是要求的总和啦~~
还是很好想象滴~~~
记得要注意边界条件matrix.empty()、i == 0、j == 0的时候~~~
当时写了很多代码写完就直接submit solution竟然直接AC了。。。//#这也能AC系列#

class NumMatrix {
public:
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if(matrix.empty())
            return ;
        int n = matrix[0].size();
        v = vector<vector<int>> (m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    v[i][j] = matrix[0][0];
                } else if(i == 0) {
                    v[i][j] = v[i][j-1] + matrix[i][j];
                } else if(j == 0) {
                    v[i][j] = v[i-1][j] + matrix[i][j];
                } else {
                    v[i][j] = v[i-1][j] + v[i][j-1] + matrix[i][j] - v[i-1][j-1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0) {
            return v[row2][col2];
        } else if(row1 == 0) {
            return v[row2][col2] - v[row2][col1-1];
        } else if(col1 == 0) {
            return v[row2][col2] - v[row1-1][col2];
        } else {
            return v[row2][col2] - v[row1-1][col2] - v[row2][col1-1] + v[row1-1][col1-1];
        }
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);