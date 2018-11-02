// 438. Find All Anagrams in a String
// 4120 ms

func findAnagrams(_ s: String, _ p: String) -> [Int] {
    let n = p.count
    var arr = Array(repeating: 0, count: s.count) , i = 0, c: Character, j = 0

    var pArr = Array(repeating: 0, count: 26)
    p.utf8.forEach({ pArr[Int($0-97)] += 1 })
    let pSet = pArr.enumerated().filter({$0.element > 0}).map({ Character(UnicodeScalar($0.offset + 97)!)  })

    while i + n <= s.count {
        let start = s.index(s.startIndex, offsetBy: i)
        let end = s.index(s.startIndex, offsetBy: i + n)
        c = s[start]
        let t = s[start..<end]

        var tArr = Array(repeating: 0, count: 26)
        t.utf8.forEach({ tArr[Int($0-97)] += 1 })

        if tArr == pArr {
            arr[j] = i; j += 1
            while i + n < s.count {
                let c1 = s[s.index(s.startIndex, offsetBy: i + n)]
                if c == c1 {
                    i += 1
                    c = s[s.index(s.startIndex, offsetBy: i)]
                    arr[j] = i; j += 1
                } else if !pSet.contains(c1) {
                    i += n; break
                } else {
                    break
                }
            }
        }
        i += 1
    }

    return Array(arr[0..<j])
}
