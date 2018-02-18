538. Convert BST to Greater Tree
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
题目大意：给定一个二叉搜索树（BST），将其转换为一个Greater Tree，使得原始BST的每个结点的键值被改变为原始键加上所有比BST中的原始键大的键的总和。
分析：因为BST的中序遍历是从小到大排列，那么BST的右根左遍历方式得到的就是从大到小的排列，遍历过程中对当前结点累计到sum中，并将sum的值赋值给当前结点，最后返回这棵树即可～


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
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
private:
    int sum = 0;
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        if (root->right != NULL) dfs(root->right);
        sum += root->val;
        root->val = sum;
        if (root->left != NULL) dfs(root->left);
    }
};