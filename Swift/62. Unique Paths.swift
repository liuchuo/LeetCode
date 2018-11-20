// 62. Unique Paths
// 16 ms, 39.53%
func uniquePaths(_ m: Int, _ n: Int) -> Int {
    pathMatrix = Array(repeating: Array(repeating: 0, count: n+1), count: m+1)
    return pathMatrix(m, n)
}

private var pathMatrix: [[Int]]!
private func pathMatrix(_ m: Int, _ n: Int) -> Int {
    if m <= 0 || n <= 0 { return 0 }
    if m < 2 || n < 2 { pathMatrix[m][n] = 1; return 1 }

    if pathMatrix[m-1][n] == 0 {
        pathMatrix[m-1][n] = pathMatrix(m-1, n)
    }
    if pathMatrix[m][n-1] == 0 {
        pathMatrix[m][n-1] = pathMatrix(m, n-1)
    }
    return pathMatrix[m-1][n] + pathMatrix[m][n-1]
}