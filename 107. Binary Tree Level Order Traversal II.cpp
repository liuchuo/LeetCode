107. Binary Tree Level Order Traversal II 
My Submissions QuestionEditorial Solution
Total Accepted: 76959 Total Submissions: 228408 Difficulty: Easy
Given a binary tree, return the bottom-up level order traversal of its nodes’ values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> row;
        vector<vector<int>> v;
        if(root == NULL) {
            return v;
        }
        queue<TreeNode *> q;
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
            v.insert(v.begin(), row);
            row.clear();
        }
        
        return v;
    }
};