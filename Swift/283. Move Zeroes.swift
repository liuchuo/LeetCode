// 283. Move Zeroes
// 16 ms
var j = 0
for i in 0..<nums.count {
    if nums[i] != 0 {
        nums[j] = nums[i]
        j += 1
    }
}
for i in j..<nums.count {
    nums[i] = 0
}