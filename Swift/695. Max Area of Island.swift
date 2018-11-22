// 695. Max Area of Island
// 44ms, 79.31%

func maxAreaOfIsland(_ grid: [[Int]]) -> Int {
    var i = 0, j = 0, v = 0
    var g = grid
    while i < grid.count {
        while j < grid[i].count {
            v = max(area(&g, i, j), v)
            j += 1
        }
        i += 1; j = 0
    }
    return v
}

private func area(_ g: inout [[Int]], _ i: Int, _ j: Int) -> Int {
    var v = 0
    if i < 0 || i >= g.count || j < 0 || j >= g[i].count {
        return 0
    }
    if g[i][j] == 1 {
        g[i][j] = 0; v = 1
        v += area(&g, i, j+1)
        v += area(&g, i+1, j)
        v += area(&g, i-1, j)
        v += area(&g, i, j-1)
    }
    return v
}
