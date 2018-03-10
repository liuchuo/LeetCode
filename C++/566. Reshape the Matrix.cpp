566. Reshape the Matrix
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.

题目大意：给出一个由二维数组表示的矩阵，两个正整数r和c分别代表所需的整形矩阵的行号和列号。重构后的矩阵需要以原始矩阵的所有元素按照相同的行遍数顺序填充。如果“给定参数的重塑操作是可能的和合法的，则输出新的重塑矩阵; 否则，输出原始矩阵。
分析：如果原nums的行列乘积等于r*c则返回nums，否则建立r行c列的数组，将ans[i/c][i%c] = nums[i/m][i%m]即可～

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size(), m = nums[0].size();
        if (n * m != r * c) return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < r * c; i++) ans[i/c][i%c] = nums[i/m][i%m];
        return ans;
    }
};