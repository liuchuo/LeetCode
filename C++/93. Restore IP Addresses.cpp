93. Restore IP Addresses
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

题目大意：给一个只包含数字的字符串，返回它可能组成的所有合法IP地址～
分析：i、j、k分别是点分隔的第一段、第二段、第三段的长度，从1到3，并且要给后面的段至少空一个数字的距离～这样就可以求出s1、s2、s3、s4，判断s1、s2、s3、s4是否满足条件，满足就将该结果放入result数组中～

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int len = s.length();
        for (int i = 1; i <= 3 && i <= len - 3; i++) {
            for (int j = 1; j <= 3 && j <= len - i - 2; j++) {
                for (int k = 1; k <= 3 && k <= len - i - j - 1; k++) {
                    string s1 = s.substr(0, i), s2 = s.substr(i, j), s3 = s.substr(i + j, k), s4 = s.substr(i + j + k, len);
                    if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) 
                        result.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                }
            }
        }
        return result;
    }
    bool isValid(string s) {
        return (s.length() >= 1 && s.length() <= 3 && (s[0] != '0' || s.length() == 1) && stoi(s) <= 255);
    }
};