// 206. Reverse Linked List
// 20 ms, 63.85%
func reverseList(_ head: ListNode?) -> ListNode? {
    var stack = [Int](), p = head
    while let t = p {
        stack.append(t.val)
        p = t.next
    }
    p = head
    while let t = p {
        t.val = stack.popLast()!
        p = t.next
    }
    return head
}