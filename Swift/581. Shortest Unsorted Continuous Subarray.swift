// 581. Shortest Unsorted Continuous Subarray
// 216 ms, 0%

func findUnsortedSubarray(_ nums: [Int]) -> Int {
    if nums.count < 2 { return 0 }
    let sn = nums.sorted()
    var p = -1, q = -1
    for (i, v) in zip(sn, nums).enumerated() {
        if v.0 != v.1 {
            p == -1 ? (p = i) : (q = i + 1)
        }
    }
    return q - p
}
