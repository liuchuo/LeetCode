653. Two Sum IV - Input is a BST
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False

题目大意：给一棵二叉搜索树和一个目标数字，如果这棵树中存在两个元素，这两个元素的和等于目标数字，则返回true
分析：设立set，如果set里面存在k - 当前结点的值，则返回true；每次将当前结点的值放入set中，否则返回它左子树的结果 || 右子树的结果。相当于每次比较的是当前结点i之前的所有数字中是否有和i相加为k的数字，如果有就返回true，否则就继续遍历左子树和右子树，只要其中一个满足就返回true

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
    set<int> s;
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        if (s.count(k - root->val)) return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};