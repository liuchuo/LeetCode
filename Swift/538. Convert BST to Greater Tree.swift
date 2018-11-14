// 538. Convert BST to Greater Tree
// 80 ms
private var sum = 0
func convertBST(_ root: TreeNode?) -> TreeNode? {
    if let root = root {
        convertBST(root.right)
        sum += root.val
        root.val = sum
        convertBST(root.left)
    }

    return root
}