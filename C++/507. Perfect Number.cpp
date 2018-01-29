507. Perfect Number
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)

题目大意：完美数字是指它的所有可以整除的正数中除了它本身，其他数字之和等于这个数字的数。给一个正整数n，写一个函数，当它是一个完美数字的时候返回true否则false。
分析：从2～sqrt(num)，累加所有i和num/i【因为如果从1～num一个个试是否可以整除的话会超时，而且也没必要，因为知道了除数a必然就知道了num/a这个数字也是它的除数】因为最后还有一个1没有加，所以sum一开始为1，然后返回num == sum，注意如果num本身为1，则要return false，因为1的唯一一个除数1是它本身不能累加，所以1不满足条件。

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int sum = 1;
        for (int i = 2; i <= sqrt(num); i++)
            if (num % i == 0) sum = sum + (num / i) + i;
        return num == sum;
    }
};