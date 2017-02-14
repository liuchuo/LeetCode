230. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).

题目大意：给一个二叉搜索树，返回它的第k小的数～
分析：二叉搜索树的中序遍历是从小到大排序的，将前k个遍历结果放入nums中，当nums.size() >= k的时候返回nums[k-1]～

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
    vector<int> nums;
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL || nums.size() >= k) return nums[k - 1];
        if (root->left != NULL) kthSmallest(root->left, k);
        nums.push_back(root->val);
        if (root->right != NULL) kthSmallest(root->right, k);
        return nums[k - 1];
    }
};