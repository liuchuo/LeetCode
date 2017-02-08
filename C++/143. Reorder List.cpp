143. Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

题目大意：按照L0→Ln→L1→Ln-1→L2→Ln-2→…重新排列链表～
分析：1.找到链表的中间结点mid——使用mid走一步、tail走两步的方式，直到tail走到链表尾部的时候，mid正好指向中间位置。
2.从mid结点开始将后面的链表反转，返回反转后的头结点
3.p指向前面一段链表，q指向后面一段链表，将p和q合并：首先令a和b是p和q的临时结点，然后将pq分别向后移动一位，最后将a->next = b;b->next = p;

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *p = head, *a = head, *b = head;
        ListNode *mid = findMidNode(head);
        ListNode *q = reverseList(mid);
        while (p != NULL && q != NULL) {
            a = p;
            b = q;
            p = p->next;
            q = q->next;
            a->next = b;
            b->next = p;
        }
        if (q != NULL) b->next = q;
    }
    
    ListNode* findMidNode(ListNode* head) {
        ListNode *mid = head, *tail = head, *last = head;
        while (tail != NULL && tail->next != NULL) {
            last = mid;
            mid = mid->next;
            tail = tail->next->next;
        }
        if (last != NULL) last->next = NULL;
        return mid;
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        ListNode *cur = head, *pre = NULL, *temp = NULL;
        while (cur != NULL) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};