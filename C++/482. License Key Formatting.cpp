482. License Key Formatting
Now you are given a string S, which represents a software license key which we would like to format. The string S is composed of alphanumerical characters and dashes. The dashes split the alphanumerical characters within the string into groups. (i.e. if there are M dashes, the string is split into M+1 groups). The dashes in the given string are possibly misplaced.

We want each group of characters to be of length K (except for possibly the first group, which could be shorter, but still must contain at least one character). To satisfy this requirement, we will reinsert dashes. Additionally, all the lower case letters in the string must be converted to upper case.

So, you are given a non-empty string S, representing a license key to format, and an integer K. And you need to return the license key formatted according to the description above.

Example 1:
Input: S = "2-4A0r7-4k", K = 4

Output: "24A0-R74K"

Explanation: The string S has been split into two parts, each part has 4 characters.
Example 2:
Input: S = "2-4A0r7-4k", K = 3

Output: "24-A0R-74K"

Explanation: The string S has been split into three parts, each part has 3 characters except the first part as it could be shorter as said above.
Note:
The length of string S will not exceed 12,000, and K is a positive integer.
String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
String S is non-empty.

题目大意：将序列号重置格式，首先去掉原先有的“-”，然后所有字母必须大写，而且要重新将每K位加一个“-”，如果序列号不能被K整除，则字符串开头允许小于K位～
分析：
1.将“-”去除，且用toupper将所有字符变成大些形式，存储在新的字符串temp里面；
2.先处理首部，如果len % K不等于0，就先将前面len%K个字母放入result字符串中
3.每K位增加一个“-”，如果一开始index == 0，即len能够被K整除，前面没有多余的，则不需要增加那个多余的第一个“-”～～

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result = "", temp = "";
        for(int i = 0; i < S.length(); i++) {
            if(S[i] != '-')
                temp += toupper(S[i]);
        }
        int len = temp.length(), index = 0;
        while(index < len % K)
            result += temp[index++];
        for(int i = 0; i < len - len % K; i++) {
            if(i % K == 0 && index != 0)
                result += '-';
            result += temp[index++];
        }
        return result;
    }
};