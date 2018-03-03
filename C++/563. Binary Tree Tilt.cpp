563. Binary Tree Tilt
Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input: 
         1
       /   \
      2     3
Output: 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
Note:

The sum of node values in any subtree won't exceed the range of 32-bit integer.
All the tilt values won't exceed the range of 32-bit integer.

题目大意：给定一棵二叉树，返回整棵树的倾斜度。树节点的倾斜度被定义为所有左子树节点值的总和与所有右节点值的总和之间的绝对差值。 空节点具有倾斜0。
分析：getSum函数用来计算以当前结点为根的子树的结点值总和，dfs用来遍历树，对于每个节点计算getSum的左子树和右子树之差累加，最后返回累加值～

class Solution {
public:
    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    int ans = 0;
    int getSum(TreeNode* root) {
        if (root == NULL) return 0;
        int l = getSum(root->left), r = getSum(root->right);
        return l + r + root->val;
    }
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        ans += abs(getSum(root->left)-getSum(root->right));
        dfs(root->left);
        dfs(root->right);
    }
};