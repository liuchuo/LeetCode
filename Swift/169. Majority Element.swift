// 169. Majority Element
// 60 ms
var v = 0, res = 0
var dict = [Int: Int]()
nums.forEach {
    var t = 1
    if let n = dict[$0] {
        t = n + 1
    }

    if t > v {
        res = $0
        v = t
    }
    dict[$0] = t
}

return res