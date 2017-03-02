513. Find Bottom Left Tree Value
Given a binary tree, find the leftmost value in the last row of the tree.
Example 1:
Input:
    2
   / \
  1   3
Output:
1
Example 2: 
Input:
        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7
Output:
7

题目大意：给一个二叉树，找它的最后一行的最左边的结点的值～
分析：广度优先搜索，对每一层进行遍历，result每次保存每一层的第一个值，最后层序遍历完成之后的result即为最后一行的第一个结点的值～

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int result = root->val;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode* temp;
        while (!q.empty()) {
            int size = q.size();
            result = q.front()->val;
            while (size--) {
                temp = q.front();
                q.pop();
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
        }
        return result;
    }
};