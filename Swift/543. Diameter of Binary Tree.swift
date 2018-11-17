// 543. Diameter of Binary Tree
// 32 ms
private var diameter = 0
private func diameterOfNode(_ root: TreeNode?) -> Int {
    var lv = 0, rv = 0

    if let l = root?.left {
        lv = 1 + diameterOfNode(l)
    }
    if let r = root?.right {
        rv = 1 + diameterOfNode(r)
    }
    diameter = max(diameter, lv + rv)
    return max(lv, rv)
}

func diameterOfBinaryTree(_ root: TreeNode?) -> Int {
    diameterOfNode(root)
    return diameter
}