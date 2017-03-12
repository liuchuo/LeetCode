98. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

题目大意：给一个二叉树，判断这个二叉树是不是合法的二叉搜索树～
分析：既然是二叉搜索树，那么按照左根右遍历后的结果一定是增序～所以只需要中序遍历一遍，判断遍历结果的数组是不是后面数一定大于前面数就可以了～


class Solution {
private:
    vector<int> v;
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL ||(root->left == NULL && root->right == NULL)) return true;
        inorder(root);
        for(int i = 1; i < v.size(); i++)
            if(v[i] <= v[i-1]) return false;
        return true;
    }
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
};