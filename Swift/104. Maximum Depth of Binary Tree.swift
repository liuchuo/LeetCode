// 104. Maximum Depth of Binary Tree
// 24 ms
return root == nil ? 0 : 1 + max(maxDepth(root?.left), maxDepth(root?.right))