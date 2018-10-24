// 394. Decode String
// 12 ms, 35.71%
func decodeString(_ s: String) -> String {
    var stack = [String]()
    s.forEach {
        switch $0 {
        case "]":
            var s = "", i = ""
            while let c = stack.popLast(), c != "[" {
                s = "\(c)\(s)"
            }
            while let sl = stack.last, nil != Int("\(sl)"), let c = stack.popLast() {
                i = "\(c)\(i)"
            }
            stack.append(String(repeating: s, count: Int(i)!))
        default:
            stack.append(String($0))
        }
    }

    return stack.joined()
}

