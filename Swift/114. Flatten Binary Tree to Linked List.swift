// 114. Flatten Binary Tree to Linked List
// 20 ms, 100%
func flatten(_ root: TreeNode?) {
    if let p = root {
        flatten(p.left)
        flatten(p.right)
        if let l = p.left {
            if let r = p.right {
                var lr = l
                while lr.right != nil {
                    lr = lr.right!
                }
                lr.right = r
            }
            p.right = l
            p.left = nil
        }
    }
}