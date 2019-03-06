// 98. Validate Binary Search Tree
// 28 ms, 100%

func isValidBST(_ root: TreeNode?) -> Bool {
    return isValidNode(root, Int.min, Int.max)
}

private func isValidNode(_ root: TreeNode?, _ min: Int, _ max: Int) -> Bool {
    guard let p = root else { return true }
    if p.val >= max || p.val <= min { return false }
    return isValidNode(p.left, min, p.val) && isValidNode(p.right, p.val, max)
}