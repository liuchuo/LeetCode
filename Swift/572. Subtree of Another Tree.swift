// 572. Subtree of Another Tree
// 368 ms

func isSubtree(_ s: TreeNode?, _ t: TreeNode?) -> Bool {
    return ( maxDepth(s) >= maxDepth(t) )
        && ( isSameTree(s, t)
            || (s?.left != nil && isSubtree(s?.left, t))
            || (s?.right != nil && isSubtree(s?.right, t)) )
}

private func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
    if let p = p, let q = q {
        return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right)
    } else {
        return p == nil && q == nil
    }
}

private func maxDepth(_ root: TreeNode?) -> Int {
    return root == nil ? 0 : 1 + max(maxDepth(root?.left), maxDepth(root?.right))
}