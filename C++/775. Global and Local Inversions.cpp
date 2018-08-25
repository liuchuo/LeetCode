775. Global and Local Inversions
We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions.

Example 1:

Input: A = [1,0,2]
Output: true
Explanation: There is 1 global inversion, and 1 local inversion.
Example 2:

Input: A = [1,2,0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.
Note:

A will be a permutation of [0, 1, ..., A.length - 1].
A will have length in range [1, 5000].
The time limit for this problem has been reduced.

题目大意：全局反转次数是0 <= i <j <N且A [i]> A [j]的i <j的个数，局部反转的次数是0 <= i <N且A [i]> A [i + 1]的i的个数。当且仅当全局反转的次数等于本地反转的次数时才返回true。
分析：局部反转属于全局反转，所以说这个数组里只允许出现相邻的两个数字是大小反转的，其他的若是间隔的两个数字，都只能是从小到大的顺序

1. 我第一次想到的方法：如果A的大小<=2，直接return true即可；否则，对于第i+2个数字来说，必须保证前i个数字都比第i+2个数字小，也就是说对于前i个数字的最大值都得小于i+2处的数字。所以用maxn标记前i个数字中最大的，让它和A[i+2]比较，如果出现了maxn比A[i+2]大的情况，则说明不可能满足条件，返回false，否则最后返回true。

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        if (A.size() <= 2) return true;
        for (int i = 0, maxn = -1; i < A.size() - 2; i++) {
            maxn = max(maxn, A[i]);
            if (maxn > A[i+2]) return false;
        }
        return true;
    }
};

2. 我第二次想到的方法：A[i]必定只能在它本应在的位置或这个位置的左边一个或者右边一个，不然必定会把比它大的两个数字挤到前面或者把比它小的两个数字挤到后面，因为题目中已经说明它所有的数字是0～n-1的一个排列，那么A[i]-i的绝对值必定<=1，否则就不满足条件～

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) 
            if (abs(A[i] - i) >= 2) return false;
        return true;
    }
};