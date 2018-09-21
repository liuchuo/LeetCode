// 215. Kth Largest Element in an Array
// 20 ms, 97.33%
func findKthLargest(_ nums: [Int], _ k: Int) -> Int {
    if nums.isEmpty { return 0 }
    let sn = nums.sorted(by: >)
    return (k <= sn.count && k > 0) ? sn[k-1] : sn[0]
}