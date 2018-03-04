779. K-th Symbol in Grammar
On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).

Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001
Note:

N will be an integer in the range [1, 30].
K will be an integer in the range [1, 2^(N-1)].

题目大意：在第一行，我们写一个0.现在在后面的每一行中，我们看前一行，用01代替0出现的每一个，每一次出现1代表10。现在问第N行第K数字是什么数字
分析：用递归，已知N == 1的时候返回0，为了知道第N行第K个数字的值，只要知道它在第N-1行的第(K+1)/2个数字对应的值即可，因为0对应01，1对应10，那么如果K是奇数只需和原数字相同即可，如果K是偶数只需对原对应数字取反即可～

class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        return (K % 2 == 0) ? !kthGrammar(N-1, (K+1)/2) : kthGrammar(N-1, (K+1)/2);
    }
};