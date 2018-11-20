// 617. Merge Two Binary Trees
// 100 ms
func mergeTrees(_ t1: TreeNode?, _ t2: TreeNode?) -> TreeNode? {
    let root = mergeNote(t1, t2)
    root?.left = mergeTrees(t1?.left, t2?.left)
    root?.right = mergeTrees(t1?.right, t2?.right)

    return root
}

func mergeNote(_ t1: TreeNode?, _ t2: TreeNode?) -> TreeNode? {
    if let c1 = t1, let c2 = t2 {
        return TreeNode(c1.val + c2.val)
    } else if let c1 = t1 {
        return TreeNode(c1.val)
    } else if let c2 = t2 {
        return TreeNode(c2.val)
    } else {
        return nil
    }
}