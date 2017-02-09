405. Convert a Number to Hexadecimal
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"

分析：就按照十进制转十六进制的正常逻辑来计算，先把十进制转换成二进制，然后二进制每4位转换成一个十六进制字符。对于十进制转二进制，只需要将num与15取&，并将num右移四位即可，因为不超过32位二进制，所以只需要8次即可～然后因为这样得到的result字符串是倒过来的，所以需要reverse一下～此时可能前面有多余的0，去除多余的前导0即可得到所求的十六进制result字符串～

class Solution {
public:
    string toHex(int num) {
        string result = "", s = "0123456789abcdef";
        for(int i = 1; i <= 8; i++) {
            result += s[num & 15];
            num = num >> 4;
        }
        reverse(result.begin(), result.end());
        while(result.length() > 1 && result[0] == '0')
            result = result.substr(1);
        return result;
    }
};