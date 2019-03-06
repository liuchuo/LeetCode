// 96. Unique Binary Search Trees
// 8 ms

func numTrees(_ n: Int) -> Int {
    list = Array(repeating: 1, count: n+1)
    if n >= 2 { list[2] = 2 }
    return g(n)
}

private var list: [Int]!
private func g(_ n: Int) -> Int {
    if  n > 2 && list[n] == 1 {
        list[n] = (1...n).reduce(0) { $0 + f($1, n) }
    }
    return list[n]
}

private func f(_ i: Int, _ n: Int) -> Int {
    return g(i-1) * g(n-i)
}