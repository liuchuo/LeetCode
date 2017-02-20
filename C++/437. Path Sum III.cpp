437. Path Sum III
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

分析：深度优先搜索，将root以及root->left、root->right结点分别作为开始结点计算下方是否有满足sum的和，dfs函数就是用来计算统计满足条件的个数的。dfs从TreeNode* root开始，查找是否满足sum和的值（此时的sum是部分和），分别dfs左边结点、右边结点，直到找到root->val == sum时候result++，在pathSum函数中返回result的值。

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
    int result = 0;
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        dfs(root, sum);
        return result;
    }
    
    void dfs(TreeNode* root, int sum) {
        if(root == NULL) return ;
        if(root->val == sum) result++;
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }
};