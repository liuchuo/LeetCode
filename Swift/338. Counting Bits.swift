// 338. Counting Bits
// 28ms
func countBits(_ num: Int) -> [Int] {
    var arr = Array(repeating: 0, count: num+1), i = 0
    while i <= num {
        arr[i] = i.nonzeroBitCount
        i += 1
    }

    return arr
}