357. Count Numbers with Unique Digits
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

Hint:

A direct way is to use the backtracking approach.
Backtracking should contains three states which are (the current number, number of steps to get that number and a bitmask which represent which number is marked as visited so far in the current number). Start with state (0,0,0) and count all valid number till we reach number of steps equals to 10n.
This problem can also be solved using a dynamic programming approach and some knowledge of combinatorics.
Let f(k) = count of numbers with unique digits with length equals k.
f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].

题目大意：给一个数n，求0～n位数间所有数字中，每一位数字都各不相同的数字的个数～
分析：根据提示中所给的公式，1位数字有10个，第k位有f(k) = 9 * 9 * 8 * ... (9 - k + 2)个，累加从2位到n位的f(k)的总和，再加上1位的10个数字，即为所求～

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int result = 10, cnt = 9;
        for(int i = 2; i <= n; i++) {
            cnt *= (11 - i);
            result += cnt;
        }
        return result;
    }
};