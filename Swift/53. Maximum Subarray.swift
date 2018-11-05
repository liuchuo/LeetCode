// 53. Maximum Subarray
// 12 ms, 100%
func maxSubArray(_ nums: [Int]) -> Int {
    if nums.isEmpty { return 0 }

    var gMax = nums[0], lMax = nums[0]
    for i in 1..<nums.count {
        lMax = nums[i] + max(lMax, 0)
        gMax = max(gMax, lMax)
    }

    return gMax
}