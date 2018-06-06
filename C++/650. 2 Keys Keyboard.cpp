650. 2 Keys Keyboard
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Note:
The n will be in the range [1, 1000].

题目大意：一开始给一个A，每次只能复制所有、或者粘贴上一次复制的内容。问要想最后变成n个A，至少得经过多少步～
分析：可以用贪心算法解决，i从2到√n，尝试是否能被n整除，如果能被整除，说明可以通过复制1次粘贴i-1次得到，则计数器ans加上i次，然后将n除以i。再次判断是否能被i整除，直至不能整除为止。然后尝试下一个i……最终n如果等于1则直接返回ans，否则要加上n表示对A复制一次粘贴n-1次

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for (int i = 2; i <= sqrt(n); i++) {
            while (n % i == 0) {
                ans += i;
                n /= i;
            }
        }
        if (n != 1) ans += n;
        return ans;
    }
};