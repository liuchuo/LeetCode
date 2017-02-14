129. Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

题目大意：给一个二叉树，上面的数字是0～9中的一个，每一个根到叶子结点的路径都代表一个数字。比如1->2->3就是组成一个数字123。找所有根到叶子结点组成数字的总和～
分析：设总和为result～从根结点开始深度优先搜索，如果已经是叶子结点（即左孩子和右孩子都为空）的时候，就将result累加root->val；否则如果左子树不为空，左子树的val值累加root->val的10倍，这样到最后叶子节点的值就变成了根结点到叶子节点组成的数字的值～


class Solution {
public:
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return result;
    }
private:
    int result = 0;
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            result += root->val;
            return;
        }
        if (root->left != NULL) {
            root->left->val += root->val * 10;
            dfs(root->left);
        }
        if (root->right != NULL) {
            root->right->val += root->val * 10;
            dfs(root->right);
        }
    }
};