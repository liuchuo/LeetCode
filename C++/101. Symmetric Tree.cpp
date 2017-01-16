101. Symmetric Tree 
My Submissions QuestionEditorial Solution
Total Accepted: 103156 Total Submissions: 305366 Difficulty: Easy
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.


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
    bool func(TreeNode *left, TreeNode *right) {
        if(left == NULL && right == NULL)
            return true;
        if(left != NULL && right != NULL && left->val == right->val) {
            return func(left->left, right->right) && func(left->right, right->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return func(root->left, root->right);
    }
};