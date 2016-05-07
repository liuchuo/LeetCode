257. Binary Tree Paths  
dfs、递归
My Submissions QuestionEditorial Solution
Total Accepted: 43816 Total Submissions: 154856 Difficulty: Easy
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

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
    void dfs(vector<string> &v, TreeNode *node, string s) {
        if(node->left == NULL && node->right == NULL) {
            v.push_back(s);
            return ;
        }
        if(node->left != NULL) {
            dfs(v, node->left, s + "->" + to_string(node->left->val));
        }
        if(node->right != NULL) {
            dfs(v, node->right, s + "->" + to_string(node->right->val));
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(root == NULL) {
            return v;
        }
        dfs(v, root, to_string(root->val));
        return v;
    }
};