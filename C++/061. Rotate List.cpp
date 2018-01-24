61. Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

题目大意：将一个链表向右循环k次，返回这个链表～
分析：计算出整个链表的长度len，如果要向右循环k次，则新的head指针应该在往右移动len - k % len处。（如果向右移动的距离moveDistance == len，那么直接返回head即可），newhead之前的一个指针的next应为NULL。并且尾部NULL前的tail指针处，tail的next应该为原来的head，最后返回newhead～

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int len = 0;
        ListNode *newhead = head, *tail = head, *p = head;
        while (p != NULL) {
            if (p->next == NULL)
                tail = p;
            len++;
            p = p->next;
        }
        int moveDistance = len - k % len;
        if (moveDistance == len) return head;
        for (int i = 0; i < moveDistance - 1; i++) {
            newhead = newhead->next;
        }
        ListNode *temp = newhead;
        newhead = newhead->next;
        temp->next = NULL;
        tail->next = head;
        return newhead;
    }
};