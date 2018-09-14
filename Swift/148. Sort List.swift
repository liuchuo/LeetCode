// 148. Sort List
// 112 ms, 100%
func sortList(_ head: ListNode?) -> ListNode? {
    var arr = Array(repeating: 0, count: 256*128)
    var i = 0, p = head
    while let q = p {
        arr[i] = q.val
        p = q.next; i += 1
    }
    arr = Array(arr[..<i]).sorted()

    p = head; i = 0
    while let q = p {
        q.val = arr[i]
        p = q.next; i += 1
    }

    return head
}