328. Odd Even Linked List
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...

题目大意：给一个单链表，将奇数结点放到一起，然后将偶数结点放到一起并放在奇数结点的后面返回～
分析：设立odd、even和evenHead三个指针，odd负责将所有奇数结点连接在一起，even负责把所有偶数结点连接在一起，而evenHead指向head->next表示偶数结点的头结点。将所有的串联好后将odd->next = evenHead, 最后返回head～


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return head;
        ListNode *odd = head, *even = head->next, *evenHead = head->next;
        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};