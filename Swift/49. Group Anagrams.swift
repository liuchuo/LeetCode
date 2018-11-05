// 49. Group Anagrams
// 164 ms, 58.49%
func groupAnagrams(_ strs: [String]) -> [[String]] {
    var dict = [String: [String]]()
    strs.forEach {
        let s = String($0.sorted())
        dict[s] = (dict[s] == nil) ? [$0] : dict[s]! + [$0]
    }
    return dict.map({$0.value})
}