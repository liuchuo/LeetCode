LeetCode 371. Sum of Two Integers

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

分析：位运算~
首先，已知异或（就是这个“^”符号）可以得到：
0^0 = 0
0^1 = 1
1^1 = 0
正是位相加时该位的结果~（只不过还有个进位没加罢了~）
所以对于还没有加进位的result，result可以暂时等于a^b

其次，已知与运算（就是这个“&”符号）可以得到：
0&0 = 0
0&1 = 0
1&1 = 1
正是位相加时候有进位的那一位标注为了1~
但是进位是往前一个位相加上去的呀~
所以carry = (a & b) << 1

现在处理要把result加上进位的事情~
如果进位carry等于0，那么不用加~直接等于result的值就好了~
如果进位不等于0，那么就要把result和carry的值按位相加~
按位相加的结果也可能导致进位~所以先用个临时变量temp把carry的值保存，然后令carry = (result & temp) << 1（也就是result和原来carry按位相加后进位的结果~），然后result = result ^ temp（也就是result和原来carry按位相加的结果~），不断循环往复，直到有一次carry等于0，不再需要进位了~~~~

class Solution {
public:
    int getSum(int a, int b) {
        int carry = (a & b) << 1;
        int result = (a ^ b);
        while(carry != 0) {
            int temp = carry;
            carry = (result & temp) << 1;
            result = result ^ temp;
        };
        return result;
    }
};