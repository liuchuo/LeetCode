108. Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

题目大意：给一个升序数组，把它转化为一个高度平衡的二叉搜索树
分析：设立left和right，mid = (left + right) / 2，每次将数组的中点mid的值为根结点的值，中点左边为根结点的左子树，右边为根结点的右子树～递归求解～

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* func(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = func(nums, left, mid - 1);
        root->right = func(nums, mid + 1, right);
        return root;
    }
};