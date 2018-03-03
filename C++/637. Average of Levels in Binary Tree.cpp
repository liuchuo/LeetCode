637. Average of Levels in Binary Tree
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node’s value is in the range of 32-bit signed integer.

题目大意：计算一棵树的每一层结点的值的平均值
分析：用广度优先搜索，当!q.empty()时，每次将当前队列q中的元素个数保存在n中，表示当前层有n个元素，对这n个元素遍历取出每一个，然后将他们的孩子节点放入队列q中，并累加这一层元素的值保存在sum中，最后将sum/n的值放入ans数组中，返回ans数组即可～

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                sum += t->val;
            }
            ans.push_back(sum * 1.0 / n);
        }
        return ans;
    }
};