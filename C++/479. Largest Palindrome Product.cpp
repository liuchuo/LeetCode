479. Largest Palindrome Product
Find the largest palindrome made from the product of two n-digit numbers.
Since the result could be very large, you should return the largest palindrome mod 1337.
Example:
Input: 2
Output: 987
Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
Note:
The range of n is [1,8].

题目大意：找到由两个n位数字乘积得到的最大回文。由于结果可能非常大，返回最大回文的%1337后的结果。
分析：l是两位数的最小值，r是两位数的最大值，从r到1能够组成的回文是r的字符串+r倒置后的字符串组成的字符串，将这个回文字串转为long型的ans，j从r到根号ans中，判断是否有j可以满足能被ans整除的j，并且这个除以的结果是小于r的，如果找到了返回ans%1337的结果，因为如果n == 1的时候比较特殊，组成的回文串是9，所以如果for循环后依然没有返回，说明遇到了n=1，那么最后就单独返回9～ 

class Solution {
public:
    int largestPalindrome(int n) {
        int l = pow(10, n-1), r = pow(10, n) - 1;
        for (int i = r; i >= 1; i--) {
            string s = to_string(i);
            string t = s;
            reverse(t.begin(), t.end());
            long ans = stol(s + t);
            for (long j = r; j * j >= ans; j--)
                if (ans % j == 0 && ans / j <= r) return ans % 1337;
        }
        return 9;
    }
};