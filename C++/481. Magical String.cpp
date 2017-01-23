481. Magical String 
A magical string S consists of only '1' and '2' and obeys the following rules:

The string S is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string S itself.

The first few elements of string S is the following: S = "1221121221221121122……"

If we group the consecutive '1's and '2's in S, it will be:

1 22 11 2 1 22 1 22 11 2 11 22 ......

and the occurrences of '1's or '2's in each group are:

1 2	2 1 1 2 1 2 2 1 2 2 ......

You can see that the occurrence sequence above is the S itself.

Given an integer N as input, return the number of '1's in the first N number in the magical string S.

Note: N will not exceed 100,000.

Example 1:
Input: 6
Output: 3
Explanation: The first 6 elements of magical string S is "12211" and it contains three 1's, so return 3.

分析：直接按照这个字符串的构造方法还原这个字符串s：首先初始化s = "122",让index指向下标为2处，开始根据index指向的字符在s后面添加字符串，如果指向的是2就添加2个，如果指向的是1就添加一个，具体添加什么字符以当前s的末尾一位的字符是1还是2为准，如果s当前最后一个字符是1就添加2，反之添加1～还原好了之后用count直接计算字符串从begin()到n长度处一共有多少个'1'字符～～

class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int index = 2;
        while(s.length() < n) {
            int cnt = s[index] - '0';
            char c = (s.back() == '1' ? '2' : '1');
            string temp(cnt, c);
            s += temp;
            index++;
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};