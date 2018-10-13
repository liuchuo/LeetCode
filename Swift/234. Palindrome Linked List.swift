// 234. Palindrome Linked List
// 60 ms, 100%
func isPalindrome(_ head: ListNode?) -> Bool {
    var arr = Array(repeating: -1, count: 999999), p = head
    var i = 0, j = 0

    while let q = p {
        arr[i] = q.val
        p = q.next; i+=1
    }

    j = i-1; i = 0

    while i < j {
        if arr[i] != arr[j] { return false }
        i+=1; j -= 1
    }

    return true
}