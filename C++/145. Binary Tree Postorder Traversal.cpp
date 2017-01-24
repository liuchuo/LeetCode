145. Binary Tree Postorder Traversal 
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

分析：后序遍历，左右根～

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
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return result;
    }
    void dfs(TreeNode* root) {
        if(root == NULL) return;
        dfs(root->left);
        dfs(root->right);
        result.push_back(root->val);
    }
};