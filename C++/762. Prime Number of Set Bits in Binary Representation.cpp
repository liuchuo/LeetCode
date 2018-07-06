762. Prime Number of Set Bits in Binary Representation
Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.
(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)
Example 1:
Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
Example 2:
Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
Note:
L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.

题目大意：给两个数L和R，在[L, R]区间寻找数字的二进制中1的个数是素数的数字个数
分析：R不超过10的6次方，也就是不超过2的20次方，那么判断是否为素数只需判断是否等于2 3 5 7 11 13 17 19即可，用bitset也只需20位表示即可，用count函数计算1的个数，然后用cnt统计后返回～

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int cnt = 0, hash[20] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};
        for (int i = L; i <= R; i++) {
            bitset<20> b(i);
            if(hash[b.count()]) cnt++;
        }
        return cnt;
    }
};