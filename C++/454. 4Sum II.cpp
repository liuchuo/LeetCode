454. 4Sum II
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

题目大意：给四个长度相等的整型数组A、B、C、D，寻找i，j，k，l使得A[i] + B[j] + C[k] + D[l] = 0，求问有多少个这样的i，j，k，l组合～
分析：设立两个map，m1和m2，m1中存储A、B数组中的元素两两组合的和以及出现的次数，如m1[i] = j表示A、B两数组中各取一个元素相加的和为i的个数有j个～这样我们就能把A+B+C+D = 0的问题转化成A+B的和为sum，求C+D中有没有-sum可以满足相加等于0～如果m1[sum]的个数是cnt1，m2[0-sum]的个数是cnt2，那么就能构成cnt1*cnt2个组合～将所有满足条件的结果累加即可得到result的值～

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> m1, m2;
        int result = 0, n = A.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int t1 = A[i] + B[j];
                int t2 = C[i] + D[j];
                m1[t1]++;
                m2[t2]++;
            }
        }
        for(auto it = m1.begin(); it != m1.end(); it++)
            result += it->second * m2[0 - it->first];
        return result;
    }
};