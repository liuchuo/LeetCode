// 100. Same Tree
// 8 ms
if let p = p, let q = q {
    return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right)
} else {
    return p == nil && q == nil
}