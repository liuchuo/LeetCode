// 101 Symmetric Tree    
// 16 ms
func isSymmetricTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
    if let p = p, let q = q {
        return p.val == q.val && isSymmetricTree(p.left, q.right) && isSymmetricTree(p.right, q.left)
    } else {
        return p == nil && q == nil
    }
}

func isSymmetric(_ root: TreeNode?) -> Bool {
    return isSymmetricTree(root?.left, root?.right)
}

