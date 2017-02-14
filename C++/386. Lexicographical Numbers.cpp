386. Lexicographical Numbers
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.

题目大意：给一个整数n，将1-n所有数按照字典序排序～
分析：从1～9分别深度优先遍历，对于每一次遍历，继续深度优先它的10 * cur + i（i从1～9），只要符合范围的就将该数字cur放入result数组中～最后返回result即可～

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        this->n = n;
        for (int i = 1; i <= 9; i++)
            dfs(i);
        return result;
    }
private:
    vector<int> result;
    int n;
    void dfs(int cur) {
        if (cur > n) return;
        result.push_back(cur);
        for (int i = 0; i <= 9; i++)
            dfs(10 * cur + i);
    }
};