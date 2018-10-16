// 287. Find the Duplicate Number
// 56 ms
func findDuplicate(_ nums: [Int]) -> Int {
    let sn = nums.sorted()
    var i = 1
    while i < nums.count {
        if sn[i-1] == sn[i] { return sn[i] }
        i += 1
    }

    return -1
}