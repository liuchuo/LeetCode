498. Diagonal Traverse
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
The total number of elements of the given matrix will not exceed 10,000.

题目大意：按照如图所示方向遍历一个m*n的二维数组，将元素按序放入一维数组中返回～
分析：先假设所有的方向都是斜向上的，也就是从matrix[0][0]开始，matrix[1][0]、matrix[2, 0]...matrix[m-1][0]也就是第一列的所有数为开头，然后还有最后一行的所有数为开头，寻找matrix[i-1][j+1]是否存在，存在就将它放入temp数组中，temp的每一行表示斜着的一行元素的序列。
这样当temp数组的行数是奇数的时候，就从后往前一次放入到result数组中，如果是偶数就从前往后依次放入result数组中，返回result数组即为所求～

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if (m == 0) return result;
        int n = matrix[0].size(), index = 0;
        vector<vector<int>> temp(m + n - 1);
        for (int i = 0; i < m; i++, index++) {
            temp[index].push_back(matrix[i][0]);
            for (int x = i, y = 0; x - 1 >= 0 && y + 1 < n; x--, y++)
                temp[index].push_back(matrix[x-1][y+1]);
        }
        for (int j = 1; j < n; j++, index++) {
            temp[index].push_back(matrix[m-1][j]);
            for (int x = m - 1, y = j; x - 1 >= 0 && y + 1 < n; x--, y++)
                temp[index].push_back(matrix[x-1][y+1]);
        }
        for (int i = 0; i < m + n - 1; i++) {
            if (i % 2 == 1) {
                for (int j = temp[i].size() - 1; j >= 0; j--)
                    result.push_back(temp[i][j]);
            } else {
                for (int j = 0; j < temp[i].size(); j++)
                result.push_back(temp[i][j]);
            }
        }
        return result;
    }
};