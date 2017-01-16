19. Remove Nth Node From End of List 
My Submissions QuestionEditorial Solution
Total Accepted: 104216 Total Submissions: 355297 Difficulty: Easy
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

Subscribe to see which companies asked this question


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL)
            return NULL;
        ListNode *p = head;
        ListNode *q = head;
        for(int i = 1; i <= n; i++) {
            p = p->next;
        }
        if(p == NULL) {
            head = head->next;
            return head;
        }
        p = p->next;
        while(p != NULL) {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return head;
    }
};