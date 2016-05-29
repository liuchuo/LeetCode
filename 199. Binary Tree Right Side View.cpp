199. Binary Tree Right Side View
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

分析：这道题可以用广度优先搜索也可以用深度优先搜索。这里用广度优先方法解决：
如果root为空，则返回空vector。
建立存放TreeNode指针的队列，将root结点入队；
出队root的同时入队root的存在的left和right结点；
按照层序遍历的方式，把每一层的最后一个结点的值存入vector中，最后返回vector。

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;
        if(root == NULL)
            return v;
        q.push(root);
        TreeNode* h;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                h = q.front();
                q.pop();
                if(h->left != NULL)
                    q.push(h->left);
                if(h->right != NULL)
                    q.push(h->right);
            }
            v.push_back(h->val);
        }
        return v;
    }
};