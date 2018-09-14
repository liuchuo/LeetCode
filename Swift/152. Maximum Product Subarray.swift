// 152. Maximum Product Subarray
// 40 ms, 12.50%
func maxProduct(_ nums: [Int]) -> Int {
    if nums.isEmpty { return 0 }
    var gm = nums[0], lmax = nums[0], lmin = nums[0], i = 1
    while i < nums.count {
        let t = [lmax * nums[i], nums[i], lmin * nums[i]]
        lmin = t.min()!
        lmax = t.max()!
        gm = max(lmax, gm)
        i += 1
    }

    return gm
}