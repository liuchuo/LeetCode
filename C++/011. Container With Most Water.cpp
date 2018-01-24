11. Container With Most Water 
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

题目大意：给出一个数组height, height[i] = j表示横坐标为i处的高为j，以(i, j)与x轴作垂线段，计算两条垂线段和x轴组成的容器能装的最多的水的容量是多少～
分析：容器两条边中取最短的那条边为影响容器容积的高，所以说，我们先假设left和right分别在最左边最右边，要想求得容器容积的最大值，需要考虑改变最短边的高度，如果左边短就让left++，如果右边短就让right--，直到直到一个area容积最大的值返回～

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, area = 0;
        while(left < right) {
            area = max(area, min(height[left], height[right]) * (right - left));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return area;
    }
};