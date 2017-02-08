396. Rotate Function
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.

分析：算出每个F[i]，求出最大值maxn。
每个F[i]可由前一步F[i-1]得到，F[i] = F[i - 1] + sum - len * A[len - i]，其中sum为A[i]总和，len为A[i]长度～找到这个关系后就能求得F[i]的所有值～

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len = A.size(), sum = 0;
        if(len == 0)
            return 0;
        vector<int> F(len);
        for(int i = 0; i < len; i++) {
            sum += A[i];
            F[0] += i * A[i];
        }
        int maxn = F[0];
        for(int i = 1; i < len; i++) {
            F[i] = F[i - 1] + sum - len * A[len - i];
            maxn = max(F[i], maxn);
        }
        return maxn;
    }
};