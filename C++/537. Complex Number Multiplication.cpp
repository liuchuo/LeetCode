537. Complex Number Multiplication
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.

题目大意：给两个复数，求两个数的乘积
分析：使用sscanf和ssprinf，(m+ni)*(p+qi)=(m*p-n*q)*(n*p+m*q)i

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        char t[200];
        int m, n, p, q;
        sscanf(a.c_str(), "%d+%di", &m, &n);
        sscanf(b.c_str(), "%d+%di", &p, &q);
        sprintf(t, "%d+%di", (m*p-n*q), (n*p+m*q));
        string ans = t;
        return ans;
    }
};