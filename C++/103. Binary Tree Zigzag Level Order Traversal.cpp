103. Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes values. (ie, from left to right, then right to left for the next level and alternate between).
For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

分析：和层序遍历一样的代码，只需要加几行代码就行~~~因为要之字型存储这个二叉树~~~
所以只不过在行数为双数的时候需要对当前行进行一次所有元素的倒置~可以用stack也可以用数组头尾两两交换的方法~~
只需要在存入二维数组vector<vector> v之前倒置好row数组，再push_back到v里面就行~
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int> row;
        vector<vector<int>> v;
        queue<TreeNode *> q;
        if(root == NULL)
            return v;
        q.push(root);
        TreeNode *temp;
        int lev = 0;
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
            if(lev % 2) {
                int n = row.size();
                for(int i = 0; i < n/2; i++) {
                    swap(row[i], row[n-i-1]);
                }
            }
            v.push_back(row);
            lev++;
            row.clear();
        }
        return v;
    }
};