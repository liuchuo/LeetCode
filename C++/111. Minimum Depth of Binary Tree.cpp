111. Minimum Depth of Binary Tree 
My Submissions QuestionEditorial Solution
Total Accepted: 101139 Total Submissions: 331361 Difficulty: Easy
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        if(root->left == NULL && root->right != NULL)
            return minDepth(root->right) + 1;
        if(root->right == NULL && root->left != NULL)
            return minDepth(root->left) + 1;
        if(root->left != NULL && root->right != NULL) {
            int leftdepth = minDepth(root->left);
            int rightdepth = minDepth(root->right);
            return leftdepth < rightdepth ? leftdepth + 1 : rightdepth + 1;
        }
    }
};