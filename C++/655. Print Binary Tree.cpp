655. Print Binary Tree
Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node’s value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
Note: The height of binary tree is in the range of [1, 10].

题目大意：按照以下规则在一个m * n的二维字符串数组中打印一个二叉树：
行号m应该等于给定二叉树的高度。
列号n应始终为奇数。
根节点的值（以字符串格式）应该放在第一行的正中间。 根节点所属的行和列将剩余空间分成两部分（左下部分和右下部分）。 您应该在左下角打印左侧子树，并在右下侧打印右侧子树。 左下部分和右下部分应该具有相同的尺寸。 即使一个子树不存在，而另一个子树不存在，您也不需要为无子树打印任何东西，但仍然需要留下与另一子树相同的空间。 但是，如果两个子树都没有，那么你就不需要为它们留下空间。
每个未使用的空间应该包含一个空字符串“”。
按照相同的规则打印子树。
分析：首先计算出树的高度h，然后建立h行、(2的h次方-1)列的字符串数组，进行先序遍历，设立l和r表示当前填充的子树对应的字符串数组的左右下标区域，h表示当前的层数，每次将root->val的值存储入ans[h][mid]中，其中mid=(l+r)/2，然后继续遍历左子树和右子树，将区间分为0～mid-1和mid+1～r，高度h加1，直至遍历完成后返回ans数组～

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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int c = pow(2, h) - 1;
        vector<vector<string>> ans(h, vector<string>(c));
        dfs(root, 0, c-1, 0, ans);
        return ans;
    }
private:
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    void dfs(TreeNode* root, int l, int r, int h, vector<vector<string>>& ans) {
        if (root == NULL) return;
        if (l > r) return;
        int mid = (l + r) / 2;
        ans[h][mid] = to_string(root->val);
        dfs(root->left, l, mid-1, h+1, ans);
        dfs(root->right, mid+1, r, h+1, ans);
    }
};