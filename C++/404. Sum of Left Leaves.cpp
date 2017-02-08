404. Sum of Left Leaves 
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

分析：深度优先遍历，将所有结点从根结点开始遍历一遍，设立isLeft的值，当当前结点是叶子节点并且也是左边，那就result加上它的值～

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
    int result = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        dfs(root, false);
        return result;
    }
    void dfs(TreeNode* root, bool isLeft) {
        if(root->left == NULL && root->right == NULL) {
            if(isLeft == true)
                result += root->val;
            return ;
        }
        if(root->left != NULL)
            dfs(root->left, true);
        if(root->right != NULL)
            dfs(root->right, false);
    }
};