112. Path Sum 
My Submissions QuestionEditorial Solution
Total Accepted: 99234 Total Submissions: 317747 Difficulty: Easy
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.


递归方法：
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL && sum == root->val)
                return true;
        if(hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val))
            return true;
        else
            return false;
    }
};


非递归法
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
    bool hasPathSum(TreeNode* root, int sum) {
        queue<TreeNode *> q;
        if(root == NULL)
            return false;
        q.push(root);
        TreeNode *temp;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                temp = q.front();
                q.pop();
                if(temp->left != NULL) {
                    q.push(temp->left);
                    temp->left->val += temp->val;
                }
                if(temp->right != NULL) {
                    q.push(temp->right);
                    temp->right->val += temp->val;
                }
                if(temp->left == NULL && temp->right == NULL && (temp->val == sum || temp->val == sum)) {
                        return true;
                }
            }
        }
        return false;
    }
};