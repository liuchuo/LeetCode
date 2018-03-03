654. Maximum Binary Tree
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
Note:
The size of the given array will be in the range [1,1000].

分析：用递归，l和r分别表示使用在nums[l]到nums[r]区间内的数字进行建树，每次通过idx找到l到r之间的最大值对应的下标idx，使用nums[idx]值new一个新TreeNode结点root，然后将root的左边用l～idx-1建树，右边用idx+1～r建树，然后返回root结点即完成了建树～

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(0, nums.size()-1, nums);
    }
private:
    int n;
    TreeNode* build(int l, int r, vector<int>& nums) {
        if (l > r) return NULL;
        int idx = l;
        for (int i = l + 1; i <= r; i++) {
            if (nums[i] > nums[idx]) idx = i;
        }
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = build(l, idx-1, nums);
        root->right = build(idx+1, r, nums);
        return root;
    }
};