69. Sqrt(x)
Implement int sqrt(int x).
Compute and return the square root of x.

题目大意：实现sqrt函数，返回x的sqrt结果（int型）
分析：二分法，令left = 0， right为int最大值，mid为left和right的中间值。始终保持要求的值在left和right之间。进入循环——如果mid的平方小于等于x并且mid+1的平方大于等于x则返回mid～否则：如果mid的平方小于x，说明答案在mid的右边，left = mid + 1，mid的平方大于x，说明答案在mid的左边，right = mid - 1～
注意：令left、right、mid都是long型因为为了避免mid*mid的结果超出整型范围～

class Solution {
public:
    int mySqrt(int x) {
        long left = 0, right = INT_MAX, mid = 0;
        while (true) {
            long mid = left + (right - left) / 2;
            if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
                return (int)mid;
            if (mid * mid < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
};