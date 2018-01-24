530. Minimum Absolute Difference in BST
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.

题目大意：给一棵二叉搜索树，结点的值都为非负，找到两个元素值之差的绝对值的最小值～
分析：二叉搜索树，用中序遍历后得到的结果是从小到大的元素，遍历这个中序遍历后的结果数组，就可以得到两个元素值之差的绝对值的最小值～

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        int result = INT_MAX;
        for (int i = 1; i < tree.size(); i++)
            result = min(result, tree[i] - tree[i-1]);
        return result;
    }
private:
    vector<int> tree;
    void inOrder(TreeNode* root) {
        if (root->left != NULL) inOrder(root->left);
        tree.push_back(root->val);
        if (root->right != NULL) inOrder(root->right); 
    }
};