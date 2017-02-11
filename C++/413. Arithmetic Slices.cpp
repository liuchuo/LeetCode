413. Arithmetic Slices
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.

题目大意：求一个数组中能构成至少连续三个数的等差数列的个数
分析：有一个规律是：
连续3个数构成等差数列，能组成的等差数列个数是1
连续4个数构成等差数列，能组成的等差数列个数是3（1+2）
连续5个数构成等差数列，能组成的等差数列个数是6（1+2+3）
……
所以每次当有三个构成等差数列的时候，cnt = 1，之后每连续增加一个数满足与之前的数构成等差数列，就令cnt++，并且将结果加到最终的result里面～


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int cnt = 0, result = 0;
        for(int i = 2; i < A.size(); i++) {
            if(A[i-1] - A[i-2] == A[i] - A[i-1]) {
                cnt++;
                result += cnt;
            } else {
                cnt = 0;
            }
        }
        return result;
    }
};