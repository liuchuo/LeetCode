// 21. Merge Two Sorted Lists
// 24 ms, 60.98%
func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
    var arr = [Int](), p1 = l1, p2 = l2, r = l1

    while let q1 = p1, let q2 = p2 {
        if q1.val < q2.val {
            arr.append(q1.val)
            p1 = q1.next
        } else {
            arr.append(q2.val)
            p2 = q2.next
        }
    }
    while let q1 = p1 {
        arr.append(q1.val)
        p1 = q1.next
        if p1 == nil {
            q1.next = l2
            r = l1
        }
    }
    while let q2 = p2 {
        arr.append(q2.val)
        p2 = q2.next
        if p2 == nil {
            q2.next = l1
            r = l2
        }
    }

    p1 = r
    arr.forEach {
        p1?.val = $0
        p1 = p1?.next
    }

    return r
}