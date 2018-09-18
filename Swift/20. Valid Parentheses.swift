// 20. Valid Parentheses
// 16 ms, 74.38%
func isValid(_ s: String) -> Bool {
    var stack = [Character](), b = true

    func compare(_ c: Character) -> Bool {
        guard let t = stack.popLast()  else { return false }
        return (c == ")" && t == "(") || (c == "]" && t == "[" ) || (c == "}" && t == "{")
    }

    loop: for c in s {
        switch c {
        case "(", "[", "{":
            stack.append(c)
        default:
            b = compare(c)
            if !b { break loop }
        }
    }
    
    return b && stack.isEmpty
}