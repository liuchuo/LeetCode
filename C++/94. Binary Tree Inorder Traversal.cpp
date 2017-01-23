94. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

分析：中序遍历，先遍历左子树，再输出中间，再遍历右子树～

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return result;
    }
    void dfs(TreeNode* root) {
        if(root == NULL) return ;
        dfs(root->left);
        result.push_back(root->val);
        dfs(root->right);
    }
};