476. Number Complement
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

分析：mask - 1为和num二进制位等长的所有位数为1的数，与num取^可以得到和num相反的数字。

class Solution {
public:
    int findComplement(int num) {
        int temp = num, mask = 1;
        while(temp != 0) {
            temp = temp >> 1;
            mask = mask << 1;
        }
        return num ^ (mask - 1);
    }
};