144. Binary Tree Preorder Traversal   
My Submissions QuestionEditorial Solution
Total Accepted: 118934 Total Submissions: 298694 Difficulty: Medium
Given a binary tree, return the preorder traversal of its nodes’ values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

Subscribe to see which companies asked this question


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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        if(root == NULL) {
            return v;
        }
        TreeNode *p = root;
        s.push(p);
        while(!s.empty()) {
            p = s.top();
            s.pop();
            v.push_back(p->val);
            if(p->right != NULL) {
                s.push(p->right);
            }
            if(p->left != NULL) {
                s.push(p->left);
            }
        } 
        return v;
    }
};