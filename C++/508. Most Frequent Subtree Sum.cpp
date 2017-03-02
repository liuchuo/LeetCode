508. Most Frequent Subtree Sum
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.

题目大意：给一棵树，找出现次数最多的子树和。子树和就是一个结点以及它下方所有结点构成的子树的总和，在这些总和中找一个出现次数最多的结果，如果有很多个这样的结果，返回这些结果构成的数组～
分析：首先深度优先搜索，先遍历左子树再遍历右子树，遍历的同时更新子树的根结点的值为自身+左子树和+右子树和。最后将这个子树根结点的值放入一个map中++，表示这个值出现的次数+1。这样深度优先搜索后的树的每一个结点的值都是子树和的值～
然后遍历这个map，找到最大值maxn。遍历map将出现次数为maxn的所有值放入result数组中，返回result数组即为所求～

class Solution {
private:
    map<int, int> m;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        dfs(root);
        int maxn = 0;
        for (auto it = m.begin(); it != m.end(); it++)
            maxn = max(maxn, it->second);
        for (auto it = m.begin(); it != m.end(); it++)
            if (it->second == maxn)
                result.push_back(it->first);
        return result;
    }
    
    void dfs(TreeNode* root) {
        if (root == NULL) return ;
        if (root->left != NULL) {
            dfs(root->left);
            root->val += root->left->val;
        }
        if (root->right != NULL) {
            dfs(root->right);
            root->val += root->right->val;
        }
        m[root->val]++;
    }
};