// 75. Sort Colors
// 12 ms, 68.92%
func sortColors(_ nums: inout [Int]) {
    var i0 = 0, i1 = 0, i2 = nums.count-1
    while i1 <= i2 {
        if nums[i1] == 2 {
            nums.swapAt(i1, i2)
            i2 -= 1
        } else if nums[i1] == 0 {
            nums.swapAt(i0, i1)
            i0 += 1; i1 += 1
        } else {
            i1 += 1
        }
    }
}