501. Find Mode in Binary Search Tree
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

题目大意：给一个二叉搜索树，求出现次数最多的数是哪个（哪些）～
分析：二叉搜索树的中序遍历的结果恰好是所有数的递增序列，根据中序遍历结果，对于当前遍历结点，标记maxCount为最大出现次数，tempCount为当前数字出现的次数，currentVal为当前保存的值。
首先，tempCount++表示当前的数字出现次数+1，如果当前结点的值不等于保存的值，就更新currentVal的值，并且将tempCount标记为1.
接下来，如果tempCount即当前数字出现的次数大于maxCount，就更新maxCount，并且将result数组清零，并将当前数字放入result数组中；如果tempCount只是等于maxCount，说明是出现次数一样的，则将当前数字直接放入result数组中～

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
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }
private:
    vector<int> result;
    int maxCount = 0, currentVal, tempCount = 0;
    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        tempCount++;
        if (root->val != currentVal) {
            currentVal = root->val;
            tempCount = 1;
        }
        if (tempCount > maxCount) {
            maxCount = tempCount;
            result.clear();
            result.push_back(root->val);
        } else if (tempCount == maxCount) {
            result.push_back(root->val);
        }
        inorder(root->right);
    }
};