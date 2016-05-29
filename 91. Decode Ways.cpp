91. Decode Ways
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.
For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.
分析：和爬楼梯的那道题leetcode 70. Climbing Stairs有类似之处~~~~
建立一个与String等长的dp数组~~
0.如果说当前s[i]不等于0,那先令dp[i] = dp[i-1]
1.如果s[i-1]与s[i]能够构成1~26里面的数字，那就把s[i-1]与s[i]构成一个整体，dp[i] += dp[i-2];
最后返回数组的最后一个值dp[len-1]

class Solution {
public:
    int check(char a) {
        return a != '0';
    }
    int func(char a, char b) {
        return a == '1' || a == '2' && b <= '6';
    }
    int numDecodings(string s) {
        int len = s.length();
        vector<int> dp(len, 0);
        if(len == 0 || s[0] == '0') 
            return 0;
        if(len == 1)
            return check(s[0]);
        dp[0] = 1;
        dp[1] = check(s[1]) + func(s[0], s[1]);
        for(int i = 2; i < len; i++) {
            if(check(s[i])) 
                dp[i] = dp[i-1];
            if(func(s[i-1], s[i])) 
                dp[i] += dp[i-2];
        }
        return dp[len-1];
    }
};