166. Fraction to Recurring Decimal
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Hint:

No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.

题目大意：给定两个整型数分子和分母，以小数的形式返回它们的结果，当有循环小数时，将循环的部分用括号括起来～
分析：先忽略符号，为了防止溢出，转换为long型的a和b，以绝对值形式求a/b的结果：a/b的结果是结果的整数部分，如果余数r = a % b不等于0，说明还有小数部分～
用map标记余数r应该在string result的哪个位置，如果map[r]不为0说明出现过，那么就在m[r]（出现的位置）的前面添加一个(，在result结尾添加一个)，表示这部分会循环～
注意点：1.如果除数等于0，直接返回0，为了避免出现返回-0的情况～
2.如果(numerator < 0) ^ (denominator < 0)等于1，说明他们一正一负，结果是负数，所以要在result的第一位添加一个“-”
3.如果一开始的r不等于0，说明有小数部分，则在计算小数部分之前添加一个"."

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string result = "";
        if(((numerator < 0) ^ (denominator < 0)) == 1)
            result += '-';
        long a = abs((long)numerator), b = abs((long)denominator);
        result += to_string(a / b);
        long r = a % b;
        if(r != 0) result += '.';
        map<int, int> m;
        while(r != 0) {
            if(m[r] != 0) {
                result.insert(m[r], 1, '(');
                result += ')';
                break;
            }
            m[r] = result.size();
            r = r * 10;
            result += to_string(r / b);
            r = r % b;
        }
        return result;
        
    }
};