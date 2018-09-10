// 102. Binary Tree Level Order Traversal
// 20 ms

func levelOrder(_ root: TreeNode?) -> [[Int]] {
    guard let root = root else { return [] }

    var q = [TreeNode](), lists = [[Int]]()
    q.append(root)

    while !q.isEmpty {
        lists.append(q.map { $0.val })

        q = q.reduce([]) { l, t in
            l + [t.left, t.right]
            }.compactMap({$0})
    }

    return lists
}