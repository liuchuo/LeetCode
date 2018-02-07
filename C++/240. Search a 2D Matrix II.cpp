240. Search a 2D Matrix II
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

题目大意：编写一个有效的算法，在m×n矩阵中搜索一个值。 该矩阵具有以下属性：
每行中的整数从左到右依次排列。每列中的整数按从上到下的顺序排列。
分析：对每一行进行binary_serch()，如果能够找到则return true，否则返回false

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++)
            if (binary_search(matrix[i].begin(), matrix[i].end(), target)) return true;
        return false;
    }
};