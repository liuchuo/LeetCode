415. Add Strings
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

分析：先将num1和num2倒置，然后从头到尾依次加，记得标记是否有进位sign，每次也要把进位的值加进去～如果num1加完了num2还没加完，就继续加num2的～反之同理～最后sign也要考虑有没有最高位1～所有都处理完后把result倒置～

class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        for(int i = 0; i < len1 / 2; i++)
            swap(num1[i], num1[len1 - i - 1]);
        for(int i = 0; i < len2 / 2; i++)
            swap(num2[i], num2[len2 - i - 1]);
        string result = "";
        int sign = 0, p = 0, q = 0;
        while(p < len1 && q < len2) {
            int t = (num1[p] - '0') + (num2[q] - '0') + sign;
            if(t >= 10) {
                t = t - 10;
                sign = 1;
            } else {
                sign = 0;
            }
            result += (char)(t + '0');
            p++;
            q++;
        }
        while(p < len1) {
            int t = (num1[p] - '0') + sign;
            if(t >= 10) {
                t = t - 10;
                sign = 1;
            } else {
                sign = 0;
            }
            result += (char)(t + '0');
            p++;
        }
        while(q < len2) {
            int t = (num2[q] - '0') + sign;
            if(t >= 10) {
                t = t - 10;
                sign = 1;
            } else {
                sign = 0;
            }
            result += (char)(t + '0');
            q++;
        }
        if(sign == 1)
            result += '1';
        int len = result.length();
        for(int i = 0; i < len / 2; i++) {
            swap(result[i], result[len - 1 - i]);
        }
        return result;
    }
};