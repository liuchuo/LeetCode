222. Count Complete Tree Nodes
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

题目大意：给一个完全二叉树，计算结点的个数～
分析：完全二叉树满足当最左结点和最右结点等高(h)的时候，结点数为2的h次方-1；否则等于左子树的结点数 + 右子树的结点数 + 1。且完全二叉树的左子树和右子树也是一个完全二叉树～

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode *l = root, *r = root;
        int cntLeft = 0, cntRight = 0;
        while (l != NULL) {
            l = l->left;
            cntLeft++;
        }
        while (r != NULL) {
            r = r->right;
            cntRight++;
        }
        if (cntLeft == cntRight) return pow(2, cntLeft) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};