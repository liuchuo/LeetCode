423. Reconstruct Original Digits from English
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"

题目大意：给一个非空字符串，是一些数字的单词打乱后的顺序，求还原这些数字是哪些以及多少个，按照数字增序排列～
分析：先把0～9这10个数字的字母写出来，就可以知道z、x、w、g、u可以唯一确定0、6、2、8、4的个数，然后按照06284的拼写在别的字母中减去他们的拼写，接下来可以发现按照s、r、o、f、e这样的顺序分别筛出7、3、1、5、9的个数即可～（还有更简洁的代码写法，这样写是为了清晰思路）

class Solution {
public:
    string originalDigits(string s) {
        map<char, int> m;
        int cnt[10] = {0}, temp;
        for(int i = 0; i < s.length(); i++)
            m[s[i]]++;
        temp = m['z'];
        cnt[0] = temp;
        m['z'] -= temp;
        m['e'] -= temp;
        m['r'] -= temp;
        m['o'] -= temp;
        temp = m['x'];
        cnt[6] = temp;
        m['s'] -= temp;
        m['i'] -= temp;
        m['x'] -= temp;
        temp = m['w'];
        cnt[2] = temp;
        m['t'] -= temp;
        m['w'] -= temp;
        m['o'] -= temp;
        temp = m['g'];
        cnt[8] = temp;
        m['e'] -= temp;
        m['i'] -= temp;
        m['g'] -= temp;
        m['h'] -= temp;
        m['t'] -= temp;
        temp = m['u'];
        cnt[4] = temp;
        m['f'] -= temp;
        m['o'] -= temp;
        m['u'] -= temp;
        m['r'] -= temp;
        temp = m['s'];
        cnt[7] = temp;
        m['s'] -= temp;
        m['e'] -= temp;
        m['v'] -= temp;
        m['e'] -= temp;
        m['n'] -= temp;
        temp = m['r'];
        cnt[3] = temp;
        m['t'] -= temp;
        m['h'] -= temp;
        m['r'] -= temp;
        m['e'] -= temp;
        m['e'] -= temp;
        temp = m['o'];
        cnt[1] = temp;
        m['o'] -= temp;
        m['n'] -= temp;
        m['e'] -= temp;
        temp = m['f'];
        cnt[5] = temp;
        m['f'] -= temp;
        m['i'] -= temp;
        m['v'] -= temp;
        m['e'] -= temp;
        temp = m['e'];
        cnt[9] = temp;
        m['n'] -= temp;
        m['i'] -= temp;
        m['n'] -= temp;
        m['e'] -= temp;
        string result = "";
        for(int i = 0; i <= 9; i++)
            for(int j = 0; j < cnt[i]; j++)
                result += to_string(i);
        return result;
    }
};
