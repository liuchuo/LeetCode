104. Maximum Depth of Binary Tree 
My Submissions QuestionEditorial Solution
Total Accepted: 135600 Total Submissions: 284617 Difficulty: Easy
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Subscribe to see which companies asked this question



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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        if(root->left != NULL && root->right == NULL)
            return maxDepth(root->left) + 1;
        if(root->right != NULL && root->left == NULL)
            return maxDepth(root->right) + 1;
        if(root->right != NULL && root->left != NULL) {
            int leftdepth = maxDepth(root->left);
            int rightdepth = maxDepth(root->right);
            return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
        }
    }
};