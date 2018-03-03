733. Flood Fill
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

题目大意：给定表示填充的开始像素（行和列）的坐标（sr，sc）和像素值newColor，“填充”图像。从上下左右四个方向填充，只要是和原来颜色一样的都填充为新的颜色～
分析：从(sr, sc)处遍历四个方向，用visit标记是否访问过，每次将所有和原来相同颜色的坐标填充为新的颜色并将当前坐标标记为访问过，最后返回image数组～

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        if (n == 0) return image;
        m = image[0].size();
        visit.resize(n, vector<bool>(m, false));
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
private:
    int n, m, arr[5] = {1, 0 , -1, 0, 1};
    vector<vector<bool>> visit;
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int& newColor) {
        image[sr][sc] = newColor;
        visit[sr][sc] = true;
        for (int i = 0; i < 4; i++) {
            int tx = sr + arr[i], ty = sc + arr[i+1];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && visit[tx][ty] == false && image[tx][ty] == oldColor)
                dfs(image, tx, ty, oldColor, newColor);
        }
    }
};