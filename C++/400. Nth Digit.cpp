400. Nth Digit
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

分析：个位数：1-9，一共9个,共计9个数字；2位数：10-99,一共90个，共计180个数字； 3位数：100-999，一共900个，共计270个数字……以此类推，所以先算出它在几位数的区间，然后算出它是在这个区间内的第几个数，最后算出在这个数的第几位～

class Solution {
public:
    int findNthDigit(int n) {
        long digit = 1, sum = 9;
        while(n > digit * sum) {
            n = n - digit * sum;
            sum = sum * 10;
            digit++;
        }
        int index = n % digit;
        if(index == 0)
            index = digit;
        long num = pow(10, digit - 1);
        num += (index == digit) ? (n / digit - 1) : (n / digit);
        for(int i = index; i < digit; i++)
            num = num / 10;
        return num % 10;
    }
};