48. Rotate Image 
My Submissions QuestionEditorial Solution
Total Accepted: 65299 Total Submissions: 189246 Difficulty: Medium
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

Subscribe to see which companies asked this question


//原地旋转90度。
//1.沿主对角线所有元素交换
//2.沿着垂直中轴线方向所有元素交换

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j <= i; j++)
                swap(matrix[i][j], matrix[j][i]);
                
        for(int i = 0, j = matrix.size() - 1; i < j; i++, j--)
            for(int k = 0; k < matrix.size(); k++)
                swap(matrix[k][i], matrix[k][j]);
    }
};