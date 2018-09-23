// 23. Merge k Sorted Lists
// 80 ms, 90.77%
func mergeKLists(_ lists: [ListNode?]) -> ListNode? {
    var i = 0, j = 0, fl = lists.compactMap({$0}), n = fl.count, p: ListNode?
    if n < 1 { return nil }

    var arr = Array(repeating: 0, count: 256*256)
    while i < n {
        p = fl[i]; i += 1
        while let p1 = p {
            arr[j] = p1.val
            p = p1.next; j += 1
            if p == nil, i < n {
                p1.next = fl[i]
            }
        }
    }

    arr = Array(arr[..<j]).sorted()

    i = 0; p = fl[0]
    while let q = p, i < j {
        q.val = arr[i]
        p = q.next; i += 1
    }

    return fl[0]
}