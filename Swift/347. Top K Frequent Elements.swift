// 347. Top K Frequent Elements
// 48 ms, 68%
func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
    var dict = [Int:Int]()
    nums.forEach {
        dict[$0] = (dict[$0] == nil ? 0 : dict[$0]! ) + 1
    }

    return dict.sorted(by:  { $0.value > $1.value } )[0..<k].map({$0.key})
}