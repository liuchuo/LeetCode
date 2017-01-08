461. Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 2^31.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.

分析：将x和y不断右移一位，然后比较他们的最后一位。对于右移一位，采用x / 2和 y / 2的方式，对于比较最后一位，即比较x % 2 和 y % 2，统计不相同的次数cnt，直到x和y都等于0为止

class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        while(x != 0 || y != 0) {
            if(x % 2 != y % 2)
                cnt++;
            x /= 2;
            y /= 2;
        }
        return cnt;
    }
};