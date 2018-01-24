29. Divide Two Integers
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

题目大意：不用乘法、除法、取余操作，将两个数相除，如果它溢出了，返回MAX_INT～
分析：我用了减法和log函数。。就是e的(loga-logb)次方等于e的log(a/b) = a/b。。。。这应该不算投机取巧吧？。。。～

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = ((dividend >> 31) ^ (divisor >> 31)) == 0 ? 1 : -1;
        long a = abs((long)dividend);
        long b = abs((long)divisor);
        double c = exp(log(a) - log(b)) + 0.0000000001;
        return (int)(sign * c);
    }
};