671. Second Minimum Node In a Binary Tree
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there is not any second smallest value.
题目大意：给一个非空的树，这个树所有值非负，而且每个结点只有2个孩子或者0个孩子，如果当前结点有两个孩子，则这个结点的值比它的两个孩子的值都小，要求输出这个树第二小的值。
分析：遍历树，将所有的值放入集合中，输出集合的第二个数；如果集合的大小小于等于1，则输出-1

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
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        return s.size() <= 1 ? -1 : (*++s.begin());
    }
private:
    set<int> s;
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        if (root->left != NULL) dfs(root->left);
        s.insert(root->val);
        if (root->right != NULL) dfs(root->right);
    }
};