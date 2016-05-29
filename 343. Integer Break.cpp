343. Integer Break   
My Submissions QuestionEditorial Solution
Total Accepted: 4641 Total Submissions: 11382 Difficulty: Medium
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.

Hint:

There is a simple O(n) solution to this problem.
You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

我们知道...某数的n次方结果总是比乘法大...
如果可以拆成3...那就不要选择2...包括4(是2的平方)
如果可以拆成5...依旧小于3x2=6
如果可以拆成6...依旧小于3x3=9
如果可以拆成7...依旧小于3x2x2=9
如果可以拆成8...依旧小于3x3x2=18
如果可以拆成9...依旧小于3*3*3=27
所以说拆成大数还不如变成3的次方形式。。
4  = 2 + 2
5  = 2 + 3
6  = 3 + 3
7  = 3 + 3 + 1 = 3 + 4
8  = 3 + 3 + 2 
9  = 3 + 3 + 3
10 = 3 + 3 + 3 + 1 = 3 + 3 + 4
11 = 3 + 3 + 3 + 2
12 = 3 + 3 + 3 + 3
我的意思是...如果有3 + 1 出现，那它是小于2的2次方的...
所以如果余数是1，就把3x1改成x4...
如果有3 + 2出现，那就没法拆成次方形式...
所以如果余数是2，依然是3x2...
如果有3 + 3出现，那一定大于 2的3次方...
所以如果余数是0，那就是3x3...


class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3)
            return n - 1;
        int cnt = 1;
        while(n > 2) {
            cnt = cnt * 3;
            n = n - 3;
        }
        if(n == 0) 
            return cnt;
        else if(n == 1)
            return cnt / 3 * 4;
        else 
            return cnt * 2;
    }
};