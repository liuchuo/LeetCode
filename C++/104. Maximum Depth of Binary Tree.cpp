104. Maximum Depth of Binary Tree 
My Submissions QuestionEditorial Solution
Total Accepted: 135600 Total Submissions: 284617 Difficulty: Easy
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
    int maxDepth(TreeNode* root) {
        
        if(root == nullptr)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while(!q.empty())
        {
            int count = q.size();
            while(count--)
            {
                TreeNode* n = q.front();
                q.pop();
                
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
            }
            
            depth++;
        }
        
        return depth;
    }
};
