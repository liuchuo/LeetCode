102. Binary Tree Level Order Traversal 
My Submissions QuestionEditorial Solution
Total Accepted: 98904 Total Submissions: 304078 Difficulty: Easy
Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> row;
        vector<vector<int>> v;
        queue<TreeNode *> q;
        if(root == NULL)
            return v;
        q.push(root);
        TreeNode *temp;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                temp = q.front();
                q.pop();
                row.push_back(temp->val);
                if(temp->left != NULL) {
                    q.push(temp->left);
                }
                if(temp->right != NULL) {
                    q.push(temp->right);
                }
            }
            v.push_back(row);
            row.clear();
        }
        return v;
    }
};