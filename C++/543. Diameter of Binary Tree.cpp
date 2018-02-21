543. Diameter of Binary Tree
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

题目大意：给一个二叉树，计算出任意两个节点中最长的长度并返回结果～
分析：计算每个节点的深度，并在dfs过程中将每个节点左边深度+右边深度的值的最大的值保存在ans中返回～

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    int ans = 0;
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
};