572. Subtree of Another Tree
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node’s descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.

题目大意：给定两个非空的二叉树s和t，检查树t是否具有与s的子树完全相同的结构和节点值。 s的子树是由s中的一个节点和所有这个节点的后代组成的一棵树。 树也可以被认为是它自己的一个子树。
分析：isSame判断两棵树是否相等，isSubtree中如果s->val == t->val && isSame(s, t)则返回true表示以s为根结点和以t为根结点的树相等，否则判断s->left和t是否相等，s->right和t是否相等，只要有一个相等即可返回true～

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        if (s->val == t->val && isSame(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
private:
    bool isSame(TreeNode* r, TreeNode* t) {
        if (r == NULL && t == NULL) return true;
        if (r == NULL || t == NULL || r->val != t->val) return false;
        return (isSame(r->left, t->left) && isSame(r->right, t->right));
    }
};
