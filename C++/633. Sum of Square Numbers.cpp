633. Sum of Square Numbers
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False

题目大意：给一个数c，判断是否存在两个数字a b满足a*a+b*b=c，存在就返回true，否则返回false
分析：i和j分别从根号c开始到0，如果找到了i * i + j * j == c就return true，如果i * i + j * j < c就break第二层for循环，最后如果都没有找到就返回false～

class Solution {
public:
    bool judgeSquareSum(int c) {
        int t = sqrt(c);
        for (int i = t; i >= 0; i--) {
            for (int j = t; j >= 0; j--) {
                if (i * i + j * j == c) return true;
                if (i * i + j * j < c) break;
            }
        }
        return false;
    }
};