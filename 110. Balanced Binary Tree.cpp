110. Balanced Binary Tree 
My Submissions QuestionEditorial Solution
Total Accepted: 105986 Total Submissions: 312957 Difficulty: Easy
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Subscribe to see which companies asked this question

Hide Tags

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
    int flag = 1;
    int dfs(TreeNode* root) {
        if(root == NULL)
            return 1;
        int l, r;
        if(root->left == NULL) {
           l = 0;
        } else {
           l = dfs(root->left);
        }
        if(root->right == NULL) {
           r = 0;
        } else {
           r = dfs(root->right);
        }
        if(abs(l-r) >= 2) {
            flag = 0;
        }
        return (l > r ? l : r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag;
    }
};