43. Multiply Strings
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

题目大意：给两个用字符串表示的非负整数，计算他们的乘积，结果用string表示～
分析：先将字符串num1和num2倒置，然后i和j分别遍历num1和num2，将num1[i] * num2[j]的结果加上v[i+j]本身的结果保存为temp，temp的余数保存在v[i+j]中，temp的进位累加在v[i+j+1]中。
从后向前从第一个非0数字开始将数字转化为字符保存在result字符串中，result即为所求字符串～

class Solution {
public:
    string multiply(string num1, string num2) {
        string result = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int len1 = num1.length(), len2 = num2.length();
        vector<int> v(len1 + len2, 0);
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                int temp = v[i + j] + (num1[i] - '0') * (num2[j] - '0');
                v[i + j] = temp % 10;
                v[i + j + 1] += temp / 10;
            }
        }
        int flag = 0;
        for (int i = len1 + len2 - 1; i >= 0; i--) {
            if (flag == 0 && v[i] != 0) flag = 1;
            if (flag == 1) result += to_string(v[i]);
        }
        return result == "" ? "0" : result;
    }
};