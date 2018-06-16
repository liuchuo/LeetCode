717. 1-bit and 2-bit Characters
We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Example 1:
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
Example 2:
Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
Note:

1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.

题目大意：我们有两个特殊字符。 第一个字符可以用1位表示。第二个字符可以用2位（10或11）表示。现在给出一个由几位表示的字符串。 返回最后一个字符是否是一位字符。 给定的字符串将始终以0结束。
分析：i从0开始遍历整个bits数组，当i遇到0时走一步，否则走2步，判断是否会走到最后一个元素～

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while(i < bits.size()) {
            if (i == (bits.size() - 1)) return true;
            if (bits[i] == 0) i++;
            else i += 2;
        }
        return false;
    }
};