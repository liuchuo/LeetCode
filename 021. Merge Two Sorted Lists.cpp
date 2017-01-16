21. Merge Two Sorted Lists 
My Submissions QuestionEditorial Solution
Total Accepted: 120589 Total Submissions: 342161 Difficulty: Easy
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 != NULL && l2 != NULL) {
            ListNode *p = l1;
            ListNode *q = l2;
            ListNode *t, *h;//t为新链表的连接指针，h为新链表的头指针
            if(p->val > q->val) {
                t = q;
                h = q;
                q = q->next;
            } else {
                t = p;
                h = p;
                p = p->next;
            }
            while(p != NULL && q != NULL) {
                if(p->val > q->val) {
                    t->next = q;
                    t = t->next;
                    q = q->next;
                } else {
                    t->next = p;
                    t = t->next;
                    p = p->next;
                }
                
            }
            while(p != NULL && q == NULL) {
                t->next = p;
                p = p->next;
                t = t->next;
            }
            while(p == NULL && q != NULL) {
                t->next = q;
                q = q->next;
                t = t->next;
            }
            while(p == NULL && q == NULL) {
                return h;
            }
        }
        if(l1 == NULL && l2 != NULL) {
            return l2;
        }
        if(l1 != NULL && l2 == NULL) {
            return l1;
        }
        if(l1 == NULL && l2 == NULL) {
            return NULL;
        }
    }
};