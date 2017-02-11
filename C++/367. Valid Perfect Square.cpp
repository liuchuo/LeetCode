367. Valid Perfect Square
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False

题目大意：判断所给的数是否正好是某数的平方～
分析：二分查找法，假设它是某数的平方，将该数的结果控制在left和right之间，不断循环，每次令mid为left和right的中间值，如果mid的平方等于num说明返回true；如果mid的平方小于num并且mid+1的平方大于num，说明num不是任何数的平方，夹在mid和mid+1之间～如果mid的平方小于num说明结果在mid的右边，令left = mid + 1；否则某数就是在mid的左边，right = mid - 1～～

class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 0, right = INT_MAX, mid = 0;
        while (true) {
            mid = left + (right - left) / 2;
            if (mid * mid == num)
                return true;
            if (mid * mid < num && (mid + 1) * (mid + 1) > num)
                return false;
            if (mid * mid < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
};