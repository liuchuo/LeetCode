60. Permutation Sequence
The set [1,2,3,…,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

题目大意：返回1, 2, 3...n的第k个全排列～
分析：result一开始为1 2 3 4 ... n，用C++库函数，当到第k个全排列的时候返回result～

class Solution {
public:
    string getPermutation(int n, int k) {
        string result = "";
        for (int i = 1; i <= n; i++)
            result += to_string(i);
        do {
            k--;
        } while (k > 0 && next_permutation(result.begin(), result.end()));
        return result;
    }
};