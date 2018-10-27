// 437. Path Sum III
// 472 ms 34.38%
func pathSum(_ root: TreeNode?, _ sum: Int) -> Int {
    return pathSumNote(root, sum).0
}

private func pathSumNote(_ root: TreeNode?, _ sum: Int) -> (Int, [Int]) {
    guard let p = root else { return (0, []) }

    let ls = pathSumNote(p.left, sum)
    let rs = pathSumNote(p.right, sum)
    let arr = (ls.1 + rs.1).map({$0 + p.val}) + [p.val]

    let sum = ls.0 + rs.0 + arr.filter({$0 == sum}).count
    return (sum, arr)
}

