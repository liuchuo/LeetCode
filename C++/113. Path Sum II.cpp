113. Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

分析：pathSum函数中只需dfs一下然后返回result数组即可，dfs函数中从root开始寻找到底端sum == root->val的结点，如果满足就将root->val压入path数组中，path数组压入result数组中，然后将当前结点弹出，return。不满足是最后一个结点的则不断深度优先左结点、右结点，同时处理好path数组的压入和弹出～～

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
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return result;
    }
    void dfs(TreeNode* root, int sum) {
        if(root == NULL) return ;
        if(root->val == sum && root->left == NULL && root->right == NULL) {
            path.push_back(root->val);
            result.push_back(path);
            path.pop_back();
            return ;
        }
        path.push_back(root->val);
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        path.pop_back();
    }
};