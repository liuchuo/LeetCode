515. Find Largest Value in Each Tree Row

You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]

题目大意：找二叉树每一层最大的数～然后返回一个数组表示每一层的最大的数～
分析：先用广度优先搜索对二叉树进行层序遍历，每一层设立maxn保存每一层的最大值，然后在每一层遍历完毕之后将maxn的值放入result数组中～

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode *> q;
        if (root == NULL) return result;
        q.push(root);
        TreeNode *temp;
        while (!q.empty()) {
            int size = q.size();
            int maxn = INT_MIN;
            while (size--) {
                temp = q.front();
                q.pop();
                maxn = max(maxn, temp->val);
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
            result.push_back(maxn);
        }
        return result;
    }
};