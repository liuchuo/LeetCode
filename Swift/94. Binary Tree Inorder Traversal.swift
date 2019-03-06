// 94. Binary Tree Inorder Traversal
// 8 ms, 100%

func inorderTraversal(_ root: TreeNode?) -> [Int] {
    var list = [Int](), stack = [TreeNode](), p = root

    while p != nil || !stack.isEmpty {
        if let t = p {
            stack.append(t)
            p = t.left
        } else {
            let t = stack.popLast()!
            list.append(t.val)
            p = t.right
        }
    }

    return list
}