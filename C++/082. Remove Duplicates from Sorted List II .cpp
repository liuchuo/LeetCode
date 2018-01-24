82. Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

题目大意：给一个已经排序的链表，删除所有元素值出现过2次或者以上的结点，只保留元素值仅仅出现过一次的结点～
分析：p为head的next，如果p的值和head的值不同，则将head->next置为deleteDuplicates(p)，返回head，否则直到找到第一个p不等于head的地方，返回deleteDuplicates(p)～

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = head->next;
        if (p->val != head->val) {
            head->next = deleteDuplicates(p);
            return head;
        } else {
            while (p != NULL && p->val == head->val) p = p->next;
            return deleteDuplicates(p);
        }
    }
};