24. Swap Nodes in Pairs 
My Submissions QuestionEditorial Solution
Total Accepted: 91202 Total Submissions: 260548 Difficulty: Easy
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *p, *q, *h, *t;
        p = head;
        q = head->next;
        h = q;
        while(p != NULL && q != NULL) {
            p->next = q->next;
            q->next = p;
            t = p;
            if(p->next != NULL) {
                p = p->next;
            } else {
                return h;
            }
            if(p->next != NULL) {
                q = p->next;
                t->next = q;
            } else {
                return h;
            }
        }
    }
};