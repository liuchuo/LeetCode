160. Intersection of Two Linked Lists 
My Submissions QuestionEditorial Solution
Total Accepted: 70387 Total Submissions: 232840 Difficulty: Easy
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.

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
    int getlength(ListNode *A) {
        int len = 0;
        while(A != NULL) {
            len++;
            A = A->next;
        }
        return len;
    }
    
    ListNode* func(ListNode *B, int movelen) {
        while(movelen--) {
            B = B->next;
        }
        return B;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }
        int lenA = getlength(headA);
        int lenB = getlength(headB);
        ListNode *p, *q;
        p = headA;
        q = headB;
        if(lenA > lenB) {
            p = func(headA, lenA - lenB);
        }
        if(lenA < lenB) {
            q = func(headB, lenB - lenA);
        }
        while(p != q && p != NULL && q != NULL) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};