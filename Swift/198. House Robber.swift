// 198. House Robber
// 8 ms, 100%
func rob(_ nums: [Int]) -> Int {
    if nums.count < 1 { return nums.first ?? 0 }
    var lm = 0, gm = 0
    for i in 0..<nums.count {
        let t = lm
        lm = gm
        gm = max(gm, t + nums[i])
    }

    return gm
}